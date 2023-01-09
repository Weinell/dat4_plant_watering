#include "trigger_water.h"
#include "Arduino.h"

const int pumpPin = 2;

void triggerWater(int milisDelay) {
    pinMode(pumpPin,OUTPUT);
    delay(1000);
    digitalWrite(pumpPin, HIGH);
    delay(milisDelay);
    digitalWrite(pumpPin, LOW);
}


void getMoisturePercentage()    {
    
}