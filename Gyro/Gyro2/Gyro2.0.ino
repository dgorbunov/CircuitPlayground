//Visualize the rotation of the Adafruit Circuit Playground Express relative to the earth using its 10 NeoPixels and it's MEMS accelerometer
#include <Adafruit_CircuitPlayground.h>

//create global variables
float x, y, z;

float theta = 0;

const int samplesize = 15; //array size
int angle[samplesize]; //create an array of size 10
int pos = 0; //current pos in array
int total = 0; //current total
int avg = 0; //average of array

const int threshold = 0.35; //accelerometer noise threshold
int pixel = 0; //index led for switch case

int brightness = 0; //brightness relative to x and y magnitude

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30); //set global brightness

   for (int i = 0; i < samplesize; i++) {
   angle[i] = 0; //set all array values to 0
  }
}

void loop() {
  x = CircuitPlayground.motionX(); //read x axis, etc.
  y = CircuitPlayground.motionY(); 
  z = CircuitPlayground.motionZ();
  if (x > 0.35 || x < -0.35 || y >0.35 || y < -0.35){ //noise tolerance;
     theta = atan2(y,x)*180/3.14; //calculate angle from inverse tan and convert to degrees
  } else {
  theta = 0;
    }

  total = 0;//reset all array variables for new sample
  avg = 0;
  pos = 0;
  
  for (int i = 0; i < samplesize; i++) {
  angle[pos] = theta;
  total = total + angle[pos];
  pos = pos+1;
  delay(4);
  }
  avg = total / samplesize;

 brightness = sqrt(sq(x)+sq(y)); //calculate brightness from Pyth. Theoreum
 Serial.print(brightness);

switch (avg) {
  case -75 ... -46:
  pixel = 0; //specify which pixel to light
  offleds(); //call custom function
  break;
  case -45 ... -16:
  pixel = 1;
  offleds();
  break;
  case -15 ... 15:
  pixel = 2;
  offleds();
  break; 
  case 16 ... 45:
  pixel = 3;
  offleds();
  break;
  case 46 ... 75:
  pixel = 4;
  offleds();
  break;
  case 105 ... 135:
  pixel = 5;
  offleds();
  break;
  case 136 ... 165:
  pixel = 6;
  offleds();
  break;
  case 166 ... 180:
  pixel = 7;
  offleds();
  break;
  case -180 ... -166:
  pixel = 7 ;
  offleds();
  break;
  case -165 ... -136:
  pixel = 8;
  offleds();
  break;
  case -135 ... -106:
  pixel = 9;
  offleds();
  break;
  default:
  CircuitPlayground.clearPixels();
  break;
}
//  Serial.print(" Pixel: ");
//  Serial.print(pixel);
}

int offleds() { //function to turn off other leds
  for (int p = 0; p < 10; p++) {
    
    if (p == pixel){
     CircuitPlayground.setPixelColor(pixel, brightness*4,0,100/brightness);
     p++;
    }
    
    CircuitPlayground.setPixelColor(p, 0,0,0);
  }
}

