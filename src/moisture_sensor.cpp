#include <Arduino.h>

#define powerPin = D5;
#define sensorPin = D18;

void setup() {
  // put your setup code here, to run once:
pinMode(powerPin, OUTPUT);
pinMode(sensorPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float moisture = digitalRead(sensorPin);
Serial.println(moisture);
}