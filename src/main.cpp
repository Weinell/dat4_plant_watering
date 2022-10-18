#include "wifi_functionality.h"
#include "http_functionality.h"


void setup() {
    setupWifi();
    setupHTTP();
}

void loop() {
    loopHTTP();
}
