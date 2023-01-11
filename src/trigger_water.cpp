#include "trigger_water.h"
#include "Arduino.h"
#include "moisture_sensor.h"
#include <Arduino.h>

const int pumpPin = 2;

int threshold = 40;


void triggerWater(int milisDelay) {
    pinMode(pumpPin,OUTPUT);
    delay(1000);
    digitalWrite(pumpPin, HIGH);
    delay(milisDelay);
    digitalWrite(pumpPin, LOW);
}

void automaticWater()   {
    int moisture = measureMoisture();
    if(moisture <= threshold)
    {
        Serial.println("Automatically watering!");
        triggerWater(1000);
    }    
}
