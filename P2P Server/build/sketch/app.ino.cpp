#include <Arduino.h>
#line 1 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
#line 1 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
#include <ESP8266WiFi.h>

const char *ssid = "Ngoc Linh";
const char *password = "0753827726";
#line 5 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
void setup();
#line 23 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
void loop();
#line 5 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
void setup()
{
    Serial.begin(115200);
    Serial.println("Setup");

    Serial.printf("Connecting to %s \n", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
}
