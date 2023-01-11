#include "wifi_functionality.h"
#include "http_functionality.h"
#include "Arduino.h"
#include "moisture_sensor.h"
#include "trigger_water.h"


void setup() {
    Serial.begin(9600);
    setupWifi();
    
}

void loop() {
    moisturePercentPOST();
    automaticWater();
    delay(1000);
}
