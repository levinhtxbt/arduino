#include <Arduino.h>
#line 1 "d:\\Arduino\\BlynkWifi\\app.ino"
#line 1 "d:\\Arduino\\BlynkWifi\\app.ino"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "e2fb324d5bfa4880a08b64765b605aff";
char ssid[] = "Green";
char pass[] = "77499981";

WidgetLED led1(V1);

BlynkTimer timer;

#line 15 "d:\\Arduino\\BlynkWifi\\app.ino"
void blinkLedWidget();
#line 29 "d:\\Arduino\\BlynkWifi\\app.ino"
void setup();
#line 39 "d:\\Arduino\\BlynkWifi\\app.ino"
void loop();
#line 15 "d:\\Arduino\\BlynkWifi\\app.ino"
void blinkLedWidget()
{
    if (led1.getValue())
    {
        led1.off();
        Serial.println("LED on V1: off");
    }
    else
    {
        led1.on();
        Serial.println("LED on V1: on");
    }
}

void setup()
{
    // Debug console
    Serial.begin(9600);

    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, blinkLedWidget);

}

void loop()
{
    Blynk.run();
    timer.run();
}

