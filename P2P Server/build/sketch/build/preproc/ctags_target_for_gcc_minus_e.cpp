# 1 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
# 1 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino"
# 2 "c:\\Users\\levin\\Documents\\Arduino\\P2P Server\\app.ino" 2

const String ssid = "Ngoc Linh";
const String password = "0753827726";
void setup()
{
    Serial.begin(115200);
    Serial.println("Setup");

    Serial.printf("Connecting to %s \n", ssid);
    WiFi.begin(ssid.toCharArray(), password.toCharArray());
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
