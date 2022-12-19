#include "wifi_functionality.h"
#include "moisture_sensor.h"
#include "pump.h"


void setup() {
    setupWifi();
    setupPump();
    setupMS();
}

void loop() {
    loopMS();
}
