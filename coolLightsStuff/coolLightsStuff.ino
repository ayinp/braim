#include <Adafruit_CircuitPlayground.h>

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

void setup() {
  CircuitPlayground.begin();
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

void loop() {
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  float z = CircuitPlayground.motionZ();

  for(int i = 0; i < 10; i++){
     if(z > 0){
     CircuitPlayground.setPixelColor(i, brightness(i, x, y), 0, brightness(i, x, y)/2);
     }
     else{
      CircuitPlayground.setPixelColor(i, brightness(i, x, y), brightness(i, x, y)/2, 0);
     }
  }

}
