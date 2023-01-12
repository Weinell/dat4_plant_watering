#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "trigger_water.h"
#include <ArduinoJson.h>
#include "wifi_functionality.h"
#include "moisture_sensor.h"


const char   HOST_NAME_MOIST[] = "https://water-steel.vercel.app/api/moist";
const char   HOST_NAME_POLL[] = "https://water-steel.vercel.app/api/poll";


void moisturePercentPOST() {

  if (WiFi.status() == WL_CONNECTED){

    HTTPClient http;

    DynamicJsonDocument doc(2048);

    int moisturePercent = measureMoisture();
    doc["moisturePercent"] = moisturePercent;

    String json;
    serializeJson(doc, json);

    http.begin(HOST_NAME_MOIST);

    Serial.println(HOST_NAME_MOIST);
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


void getAndUpdateBackendInformation() {
  WiFiClient client;
  HTTPClient http;

  http.begin(HOST_NAME_POLL);

  int httpResponse = http.GET();

  String payload = http.getString();

  Serial.println(payload);
  Serial.println(HOST_NAME_POLL);

  http.end();

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, payload);
  bool isWatering = doc["isWatering"];
  int waterTimeMS = doc["waterTimeInMs"];
  int threshold = doc["threshold"];

  Serial.println(isWatering);
  Serial.println(waterTimeMS);
  Serial.println(threshold);

  if (isWatering == true)
  {
    triggerWater(waterTimeMS);
  }

  automaticWater(threshold, waterTimeMS);
}