#include <Adafruit_CircuitPlayground.h>

float x, y, z;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(25);
}

void loop() {
  x = CircuitPlayground.motionX();
  y = CircuitPlayground.motionY();
  z = CircuitPlayground.motionZ();
  //Serial.print("x: ");
  //Serial.println(x);
  //Serial.print("  y: ");
  //Serial.println(y);
 // Serial.print("  z: ");
  //Serial.println(z);
  //Serial.print(y);
if (y>0.2){
  CircuitPlayground.setPixelColor(4, (y-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(5, (y-0.2)*25,0,0);
} else {
  CircuitPlayground.setPixelColor(4, 0,0,0);
  CircuitPlayground.setPixelColor(5, 0,0,0);
}
if (y<-0.2){
  CircuitPlayground.setPixelColor(0, (-y-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(9, (-y-0.2)*25,0,0);
} else {
  CircuitPlayground.setPixelColor(0, 0,0,0);
  CircuitPlayground.setPixelColor(9, 0,0,0);
}

if (x>0.2){
  CircuitPlayground.setPixelColor(1, (x-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(2, (x-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(3, (x-0.2)*25,0,0);
} else {
  CircuitPlayground.setPixelColor(1, 0,0,0);
  CircuitPlayground.setPixelColor(2, 0,0,0);
  CircuitPlayground.setPixelColor(3, 0,0,0);
}
if (x<-0.2){
  CircuitPlayground.setPixelColor(6, (-x-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(7, (-x-0.2)*25,0,0);
  CircuitPlayground.setPixelColor(8, (-x-0.2)*25,0,0);
} else{
  CircuitPlayground.setPixelColor(6, 0,0,0);
  CircuitPlayground.setPixelColor(7, 0,0,0);
  CircuitPlayground.setPixelColor(8, 0,0,0);
}

  delay(50);
}
