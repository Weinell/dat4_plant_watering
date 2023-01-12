#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "trigger_water.h"
#include <ArduinoJson.h>
#include "wifi_functionality.h"
#include "moisture_sensor.h"
#include <cstring>
using namespace std;

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


void getBackendInformation() {
  WiFiClient client;
  HTTPClient http;

  http.begin(client, HOST_NAME_POLL);

  int httpResponse = http.GET();

  String payload = "{}";

  if(httpResponse > 0)  {
    payload = http.getString();
  } else{
    Serial.println("Failed");
  }

  Serial.println(payload);
  Serial.println(HOST_NAME_POLL);

  //http.addHeader("Content-Type", "application/json");

  http.end();

}