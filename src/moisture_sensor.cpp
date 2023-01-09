#include "moisture_sensor.h"
#include <Arduino.h>

const int sensorPin = 4;

int airValue = 620;
int waterValue = 300;
int moistureVal = 0;
int moisturePercent = 0;


int measureMoisture() {
    moistureVal = analogRead(sensorPin);
    moisturePercent = map(moistureVal, airValue, waterValue, 0, 100);
    Serial.println(moistureVal);
    Serial.println(moisturePercent);
    return moisturePercent;
}