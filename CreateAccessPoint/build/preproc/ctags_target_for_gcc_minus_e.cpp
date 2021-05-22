# 1 "c:\\Users\\levin\\Documents\\Arduino\\CreateAccessPoint\\app.ino"
# 1 "c:\\Users\\levin\\Documents\\Arduino\\CreateAccessPoint\\app.ino"
# 2 "c:\\Users\\levin\\Documents\\Arduino\\CreateAccessPoint\\app.ino" 2

const char *password = "password";
const char *ssid = "arduino-esp8266";

void setup()
{
    Serial.begin(115200);
    Serial.print("Configuring access point...");
    //char ssid[64];
    //sprintf(ssid, "AP-%06X", ESP.getChipId());
    WiFi.softAP(ssid, password);

    // Config port cho AP
    // IPAddress local_IP(192, 168, 4, 22);
    // IPAddress gateway(192, 168, 4, 9);
    // IPAddress subnet(255, 255, 255, 0);
    // WiFi.softAPConfig(local_IP, gateway, subnet);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
}

void loop()
{
    Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
    delay(3000);
}
