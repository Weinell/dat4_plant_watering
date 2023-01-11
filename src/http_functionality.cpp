#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "trigger_water.h"
#include <ArduinoJson.h>
#include "wifi_functionality.h"
#include "moisture_sensor.h"

const char   HOST_NAME[] = "http://192.168.2.204:3000/api/health"; // hostname of web server:


void httpClient() {

  if (WiFi.status() == WL_CONNECTED){

    HTTPClient http;

    DynamicJsonDocument doc(2048);

    int moisturePercent = measureMoisture();
    doc["moisturePercent"] = moisturePercent;

    String json;
    serializeJson(doc, json);

    http.begin(HOST_NAME);

    Serial.println(HOST_NAME);
    Serial.println(json);

    http.addHeader("Content-Type", "application/json");

    //int request = http.POST("{\"moisturePercent\":\"measureMoisture()\"}");
    http.POST(json);
  
    http.end();
  }
  else{
    Serial.println("Wifi disconnected, trying to reconnect!");
    setupWifi();
  }
}
