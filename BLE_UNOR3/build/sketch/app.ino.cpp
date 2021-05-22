#include <Arduino.h>
#line 1 "d:\\Arduino\\BLE_UNOR3\\app.ino"
#line 1 "d:\\Arduino\\BLE_UNOR3\\app.ino"
#include <SoftwareSerial.h>
int rxPin = 3;
int txPin = 2;
int ledPin = 13;
char state;

SoftwareSerial hc06(txPin, rxPin);

#line 9 "d:\\Arduino\\BLE_UNOR3\\app.ino"
void setup();
#line 18 "d:\\Arduino\\BLE_UNOR3\\app.ino"
void loop();
#line 9 "d:\\Arduino\\BLE_UNOR3\\app.ino"
void setup() {
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Write data from HC06 to Serial Monitor
  if (hc06.available()) {
    state = hc06.read();
    
    Serial.println(state);
    
    switch (state)
    {
      case '1':
        digitalWrite(ledPin, HIGH);
        break;

      case '0':
        digitalWrite(ledPin, LOW);
        break;
    }
  }

  //Write from Serial Monitor to HC06
  if (Serial.available()) {
    hc06.write(Serial.read());
  }
}

