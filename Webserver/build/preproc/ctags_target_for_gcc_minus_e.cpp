# 1 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
# 1 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
# 2 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino" 2
# 3 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino" 2

const char* ssid = "Ngoc Linh";
const char* password = "0753827726";
const int led = 16; //LED pin = gpio16
/* HTML sẽ được gởi xuống client */
const char *html = "<!DOCTYPE html> <html> <head> <meta charset=\"utf-8\" /> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <title>ESP8266</title> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <script src=\"https://code.jquery.com/jquery-3.3.1.min.js\" integrity=\"sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8=\" crossorigin=\"anonymous\"></script> </head> <body> <h1>Turn on / off led</h1> <button id=\"btnTurnOn\">ON </button> <button id=\"btnTurnOff\">OFF </button> <script type=\"text/javascript\"> $(document).ready(function () { $('#btnTurnOn').on('click', function () { $.ajax({ type: 'GET', url: 'on', contentType: \"application/json\", dataType: 'json', crossDomain: true, success: function (msg) { alert('success'); }, error: function (request, status, error) { console.log(error); } }); }); $('#btnTurnOff').on('click', function () { $.ajax({ type: 'GET', url: 'off', contentType: \"application/json\", dataType: 'json', crossDomain: true, success: function (msg) { alert('success'); }, error: function (request, status, error) { console.log(error); } }); }); }); </script> </body> </html>";

/* Web Server lắng nghe ở port 80 */
ESP8266WebServer server(80);

/* hàm này được gọi khi trình duyệt truy vấn đến '/on'

 * sẽ bật đèn LED (0 = on), sau đó chuyển hướng trình duyệt

 * về lại trang chủ '/'

 */
# 17 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleOn() {
  digitalWrite(led, 0x1);
  server.send(200, "application/json", "{}");
}

/* hàm này được gọi khi trình duyệt truy vấn đến '/off'

 * sẽ tắt đèn LED (1 = off), sau đó chuyển hướng trình duyệt

 * về lại trang chủ '/'

 */
# 26 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleOff() {
  digitalWrite(led, 0x0);
  server.send(200, "application/json", "{}");
}

/* hàm này được gọi khi trình duyệt truy vấn đến trang chủ '/'

 * sẽ gởi dữ liệu HTML, cung cấp các thông tin để bật, tắt LED

 */
# 34 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
void handleRoot() {
  server.send(200, "text/html", html);
}

void setup(void){
  pinMode(led, 0x01);
  digitalWrite(led, 0x0);
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
# 56 "c:\\Users\\levin\\Documents\\Arduino\\Webserver\\app.ino"
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
