# 1 "d:\\Arduino\\BlynkWifi\\app.ino"
# 1 "d:\\Arduino\\BlynkWifi\\app.ino"



# 5 "d:\\Arduino\\BlynkWifi\\app.ino" 2
# 6 "d:\\Arduino\\BlynkWifi\\app.ino" 2

char auth[] = "e2fb324d5bfa4880a08b64765b605aff";
char ssid[] = "Green";
char pass[] = "77499981";

WidgetLED led1(1);

BlynkTimer timer;

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
