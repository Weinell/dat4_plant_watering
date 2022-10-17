#include "moisture_sensor.h"
#include <Arduino.h>

const int powerPin = 12;
const int sensorPin = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(powerPin, OUTPUT);
pinMode(sensorPin, INPUT);
Serial.begin(1115200);
}

void loop() {
  // put your main code here, to run repeatedly:
float moisture = digitalRead(sensorPin);
Serial.println(moisture);
}