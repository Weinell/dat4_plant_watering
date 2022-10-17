#include "moisture_sensor.h"
#include <Arduino.h>

const int powerPin = 13;
const int sensorPin = 12;

void setupMS() {
  // put your setup code here, to run once:
pinMode(powerPin, OUTPUT);
pinMode(sensorPin, INPUT);
//Serial.begin(1115200);
}

void loopMS() {
  // put your main code here, to run repeatedly:
float moisture = digitalRead(sensorPin);
//Serial.println(moisture);
}