#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "trigger_water.h"

const int    HTTP_PORT   = 80;
const String HTTP_METHOD = "GET"; // or "POST"
const char   HOST_NAME[] = "water-steel.vercel.app"; // hostname of web server:
const String HEALTH   = "/api/healthT";

WiFiClient client;
AsyncWebServer server(9000);

/*
void setupHTTP()     {
    //Serial.begin(1115200);
    Serial.begin(9600);
    if(client.connect(HOST_NAME, HTTP_PORT)) {
    Serial.println("Connected to server");
    } else {
    Serial.println("connection failed");
    }
    
    // send HTTP request header
    client.println(HTTP_METHOD + " " + HEALTH + " HTTP/2.0");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP request header
    delay(1000);
    while(client.available())
{
  // read an incoming byte from the server and print them to serial monitor:
    char c = client.read();
    Serial.print(c);
}

if(!client.connected())
{
  // if the server's disconnected, stop the client:
  Serial.println("disconnected");
  client.stop();
}

}*/

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
    getMoisturePercentage();
    request->send(200, "text/plain", "You got a healthy response!");
  });
 
  server.on("/redirect/external", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("https://techtutorialsx.com/");
  });
 
  server.begin();
  }

/*void healthCheckRequest()  {
  HTTPClient http;

  http.begin("http://water-steel.vercel.app/api/health"); // specify the URL
  int httpCode = http.GET(); // make the request

  if (httpCode > 0) { // check the returning code
    String payload = http.getString(); // get the request response payload
    Serial.println(httpCode); // print returning code
    Serial.println(payload); // print response payload
  } else {
    Serial.println("Error on HTTP request");
  }

  http.end(); // close the connection

  delay(4000);
}*/
