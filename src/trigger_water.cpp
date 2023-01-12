#include "trigger_water.h"
#include "Arduino.h"
#include "moisture_sensor.h"
#include <Arduino.h>
#include "http_functionality.h"

const int LEDPin = 2;
const int pumpPin = 12;

int threshold = 40;


void triggerWater(int timeMilis) {
    pinMode(pumpPin,OUTPUT);
    pinMode(LEDPin,OUTPUT);
    delay(100);
    digitalWrite(pumpPin, HIGH);
    digitalWrite(LEDPin, HIGH);
    delay(timeMilis);
    digitalWrite(pumpPin, LOW);
    digitalWrite(LEDPin, LOW);
}

void automaticWater(int threshold, int timeMilis)   {
    int moisture = measureMoisture();
    if(moisture <= threshold)
    {
        Serial.println("Automatically watering!");
        triggerWater(timeMilis);
    }    
}
