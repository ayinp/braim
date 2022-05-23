#include <Adafruit_CircuitPlayground.h>

int value;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  CircuitPlayground.clearPixels();
  
  int lightLevel = /*constrain(*/map(CircuitPlayground.lightSensor(), 1000, 0, 0, 255)/*, 0, 255)*/;

  for(int i = 0; i < 10; i++){
  CircuitPlayground.setPixelColor(i, lightLevel, lightLevel, lightLevel);
  }


  Serial.print("Light Sensor: ");
  Serial.println(lightLevel);
  
}
