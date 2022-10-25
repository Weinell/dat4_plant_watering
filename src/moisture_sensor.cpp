#include "moisture_sensor.h"
#include <Arduino.h>

const int sensorPin = 34;

int airValue = 4095;
int waterValue = 600;
int moistureVal = 0;
int moisturePercent = 0;

void setupMS() {
    //Serial.begin(1115200);
    Serial.begin(9600);
}

void loopMS() {
    moistureVal = analogRead(sensorPin);
    moisturePercent = map(moistureVal, airValue, waterValue, 0, 100);
    Serial.println(moistureVal);
    Serial.println(moisturePercent);
    delay(1000);
}