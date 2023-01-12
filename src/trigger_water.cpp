#include "trigger_water.h"
#include "Arduino.h"
#include "moisture_sensor.h"
#include <Arduino.h>
#include "http_functionality.h"

const int pumpPin = 2;

int threshold = 40;


void triggerWater(int timeMilis) {
    pinMode(pumpPin,OUTPUT);
    delay(100);
    digitalWrite(pumpPin, HIGH);
    delay(timeMilis);
    digitalWrite(pumpPin, LOW);
}

void automaticWater(int threshold, int timeMilis)   {
    int moisture = measureMoisture();
    if(moisture <= threshold)
    {
        Serial.println("Automatically watering!");
        triggerWater(timeMilis);
    }    
}
