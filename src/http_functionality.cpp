#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "trigger_water.h"
#include <ArduinoJson.h>
#include "moisture_sensor.h"

const int    HTTP_PORT   = 80;
const String HTTP_METHOD = "GET"; // or "POST"
const char   HOST_NAME[] = "water-steel.vercel.app"; // hostname of web server:
const String HEALTH   = "/api/healthT";

AsyncWebServer server(80);


void setupAsyncServer() {

  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello from ESP32 server route");
  });
 
  server.on("/water", HTTP_GET, [](AsyncWebServerRequest *request){
    triggerWater(1000);
    request->send(200, "text/plain", "I am watering!");
  });

  server.on("/health", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "You got a healthy response!");
  });

  server.on("/moist", HTTP_GET, [](AsyncWebServerRequest *request){

    int moisture = measureMoisture();

    std::string moisture_string = std::to_string(moisture);

    char moist[moisture_string.length() + 1];
    strcpy(moist, moisture_string.c_str());
  

    request->send(200, "text/plain", moist);
  });
  
  server.begin();
  }
