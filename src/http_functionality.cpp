#include "http_functionality.h"
#include "WiFiManager.h"
#include <string>


const int    HTTP_PORT   = 3030;
const String HTTP_METHOD = "GET"; // or "POST"
const char   HOST_NAME[] = "localhost"; // hostname of web server:
const String PATH_NAME   = "goodbye";

WiFiClient client;


void setupHTTP()     {
    Serial.begin(1115200);
    if(client.connect(HOST_NAME, HTTP_PORT)) {
    Serial.println("Connected to server");
    } else {
    Serial.println("connection failed");
    }
    
    // send HTTP request header
    client.println(HTTP_METHOD + " " + PATH_NAME + " HTTP/1.1");
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

}