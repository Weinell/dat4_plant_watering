#include "moisture_sensor.h"
#include <Arduino.h>

const int sensorPin = 34;

int airValue = 4095;
int waterValue = 1250;
int moistureVal = 0;
int moisturePercent = 0;


int measureMoisture() {
    moistureVal = analogRead(sensorPin);
    moisturePercent = map(moistureVal, airValue, waterValue, 0, 100);

    Serial.println(moistureVal);
    Serial.println(moisturePercent);

    if (moisturePercent > 100)
    {
        moisturePercent = 100;
        return moisturePercent;
    }
    else {
        return moisturePercent;
    }
}
