#include <Adafruit_CircuitPlayground.h>
#include <Ewma.h>

//Reginald

//0 = {-25, 46}
//1 = {-44, 26}
//2 = {-51, 0}
//3 = {-44, -26}
//4 = {-25, -46}
//5 = {25, -46}
//6 = {44, -26}
//7 = {51, 0}
//8 = {44, 26}
//9 = {25, 46}
bool red;
bool blue;
bool green;

unsigned int timer = millis() + 2000;

void setup() {
  red = false;
  blue = false;
  green = true;
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(255);
  Serial.begin(9600);
}

float dot(float x1, float y1, float x2, float y2) {
  return x1 * x2 + y1 * y2;
}

int brightness(float accx, float accy, float x, float y) {
  return constrain(map(dot(x, y, accx, accy), 500, -500, -255, 255), 0, 255);
}

int brightness(int ledNum,  float x, float y) {
  switch (ledNum) {
    case 0:
      return brightness(-25, 46, x, y);
    case 1:
      return brightness(-44, 26, x, y);
    case 2:
      return brightness(-51, 0, x, y);
    case 3:
      return brightness(-44, -26, x, y);
    case 4:
      return brightness(-25, -46, x, y);
    case 5:
      return brightness(25, -46, x, y);
    case 6:
      return brightness(44, -26, x, y);
    case 7:
      return brightness(51, 0, x, y);
    case 8:
      return brightness(44, 26, x, y);
    case 9:
      return brightness(25, 46, x, y);
  }
}

int lastPixelNum = 100;
void setPixel(int num) {
  if (num != lastPixelNum) {
    CircuitPlayground.clearPixels();
    lastPixelNum = num;
    CircuitPlayground.setPixelColor(num, 255,     0,   155);
  }
}

void changeColors(){
  red = !red;
  blue = !blue;
  green = !green;

}

constexpr float filterVal = 0.05;

Ewma filterX(filterVal);
Ewma filterY(filterVal);
Ewma filterZ(filterVal);

void loop() {
  float x = filterX.filter(CircuitPlayground.motionX());
  float y = filterY.filter(CircuitPlayground.motionY());
  float z = filterZ.filter(CircuitPlayground.motionZ());




  for (int i = 0; i < 10; i++) {
    if (blue) {
      CircuitPlayground.setPixelColor(i, 0, 0, brightness(i, x, y));
    }
    else if ( green) {
      CircuitPlayground.setPixelColor(i, 0, brightness(i, x, y), 0);
    }
    //    if (z > 0) {
    //      CircuitPlayground.setPixelColor(i, brightness(i, x, y), 0, brightness(i, x, y) / 2);
    //    }
    //    else {
    //      CircuitPlayground.setPixelColor(i, brightness(i, x, y), brightness(i, x, y) / 2, 0);
    //    }
  }

 if(millis() > timer){
    //run myRoutine every 2 seconds
    changeColors();
    timer = millis() + 2000;
  }



}
