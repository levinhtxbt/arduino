# 1 "d:\\Arduino\\BlynkWifi\\app.ino"
# 1 "d:\\Arduino\\BlynkWifi\\app.ino"



# 5 "d:\\Arduino\\BlynkWifi\\app.ino" 2
# 6 "d:\\Arduino\\BlynkWifi\\app.ino" 2

char auth[] = "e2fb324d5bfa4880a08b64765b605aff";
char ssid[] = "Nam Giang";
char pass[] = "kai692003";

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
WidgetTerminal terminal(2);

void BlynkWidgetWrite1 (BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param)
{

    // if you type "Marco" into Terminal Widget - it will respond: "Polo:"
    if (String("Marco") == param.asStr())
    {
        terminal.println("You said: 'Marco'");
        terminal.println("I said: 'Polo'");
    }
    else
    {

        // Send it back
        terminal.print("You said:");
        terminal.write(param.getBuffer(), param.getLength());
        terminal.println();
    }

    // Ensure everything is sent
    terminal.flush();
}

void setup()
{
    // Debug console
    Serial.begin(9600);

    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, blinkLedWidget);
    terminal.println(((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((section(".irom.text"))) = ("Blynk v" "0.5.4" ": Device started"); &__c[0];}))))));
    terminal.println(((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((section(".irom.text"))) = ("-------------"); &__c[0];}))))));
    terminal.println(((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((section(".irom.text"))) = ("Type 'Marco' and get a reply, or type"); &__c[0];}))))));
    terminal.println(((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((section(".irom.text"))) = ("anything else and get it printed back."); &__c[0];}))))));
    terminal.flush();
}

void loop()
{
    Blynk.run();
    timer.run();
}
