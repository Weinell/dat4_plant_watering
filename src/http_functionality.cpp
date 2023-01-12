#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "trigger_water.h"
#include <ArduinoJson.h>
#include "wifi_functionality.h"
#include "moisture_sensor.h"

const char   HOST_NAME[] = "https://water-steel.vercel.app/api/moist"; // hostname of web server:


void moisturePercentPOST() {

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

    http.POST(json);

    Serial.println(http.getString());
  
    http.end();
  }
  else{
    Serial.println("Wifi disconnected, trying to reconnect!");
    setupWifi();
  }
}
