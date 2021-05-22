#include <Arduino.h>
#line 1 "c:\\Users\\levin\\Documents\\Arduino\\CamBienAnhSang\\app.ino"
#line 1 "c:\\Users\\levin\\Documents\\Arduino\\CamBienAnhSang\\app.ino"

int quangTro = A5;
int ledPin = 9;
int brightness = 100;
#line 5 "c:\\Users\\levin\\Documents\\Arduino\\CamBienAnhSang\\app.ino"
void setup();
#line 11 "c:\\Users\\levin\\Documents\\Arduino\\CamBienAnhSang\\app.ino"
void loop();
#line 5 "c:\\Users\\levin\\Documents\\Arduino\\CamBienAnhSang\\app.ino"
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int giatriQuangtro = analogRead(quangTro); // đọc giá trị quang trở
    // Serial.print("gia tri quang tro ");
    // Serial.println(giatriQuangtro);

    // brightness = 1023 - giatriQuangtro;
    // Serial.print("do sang ");
    // Serial.println(brightness);

    // analogWrite(ledPin, brightness);
    if (giatriQuangtro > 100)
    {
        digitalWrite(ledPin, LOW);
    }
    else
    {
        digitalWrite(ledPin, HIGH);
    }

    //Serial.println(giatriQuangtro); // Xuất giá trị ra Serial Monitor

    //delay(500);
}
