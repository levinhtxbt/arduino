# 1 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
# 1 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
# 2 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino" 2
# 3 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino" 2

const char* ssid = "Ngoc Linh";
const char* password = "0753827726";
const int led = 16; //LED pin = gpio16
/* HTML sẽ được gởi xuống client */
const char *html =
 "<html>  <head>    <title>ESP8266 Webserver</title>  </head>  <body>    <a href=\"/on\">ON</a>    <a href=\"/off\">OFF</a>  </body></html>";
# 19 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
/* Web Server lắng nghe ở port 80 */
ESP8266WebServer server(80);

/* hàm này được gọi khi trình duyệt truy vấn đến '/on'

 * sẽ bật đèn LED (0 = on), sau đó chuyển hướng trình duyệt

 * về lại trang chủ '/'

 */
# 26 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleOn() {
  digitalWrite(led, 0);
  server.sendHeader("Location","/");
  server.send(301);
}

/* hàm này được gọi khi trình duyệt truy vấn đến '/off'

 * sẽ tắt đèn LED (1 = off), sau đó chuyển hướng trình duyệt

 * về lại trang chủ '/'

 */
# 36 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleOff() {
  digitalWrite(led, 1);
  server.sendHeader("Location","/");
  server.send(301);
}

/* hàm này được gọi khi trình duyệt truy vấn đến trang chủ '/'

 * sẽ gởi dữ liệu HTML, cung cấp các thông tin để bật, tắt LED

 */
# 45 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleRoot() {
  server.send(200, "text/html", html);
}

void setup(void){
  pinMode(led, 0x01);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");

  /* Chúng ta có thể biết IP của ESP8266

   * để kết nối tới nhờ gọi hàm này

   */
# 67 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
