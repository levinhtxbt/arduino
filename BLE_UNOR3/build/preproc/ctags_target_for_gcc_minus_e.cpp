# 1 "d:\\Arduino\\BLE_UNOR3\\app.ino"
# 1 "d:\\Arduino\\BLE_UNOR3\\app.ino"
# 2 "d:\\Arduino\\BLE_UNOR3\\app.ino" 2
int rxPin = 3;
int txPin = 2;
int ledPin = 13;
char state;

SoftwareSerial hc06(txPin, rxPin);

void setup() {
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  pinMode(ledPin, 0x1);
}

void loop() {
  //Write data from HC06 to Serial Monitor
  if (hc06.available()) {
    state = hc06.read();

    Serial.println(state);

    switch (state)
    {
      case '1':
        digitalWrite(ledPin, 0x1);
        break;

      case '0':
        digitalWrite(ledPin, 0x0);
        break;
    }
  }

  //Write from Serial Monitor to HC06
  if (Serial.available()) {
    hc06.write(Serial.read());
  }
}
