#include "wifi_functionality.h"
#include "http_functionality.h"
#include "Arduino.h"
#include "moisture_sensor.h"


void setup() {
    Serial.begin(9600);
    setupWifi();
    setupAsyncServer();
}

void loop() {
    //setupHTTP();


}
