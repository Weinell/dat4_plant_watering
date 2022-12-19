#include "pump.h"
#include <Arduino.h>

const int powerPin = 12;

void setupPump()    {
    pinMode(powerPin, OUTPUT);
}

void startPump()   {

    digitalWrite(powerPin, HIGH);
}

void stopPump() {
    digitalWrite(powerPin, LOW);
}