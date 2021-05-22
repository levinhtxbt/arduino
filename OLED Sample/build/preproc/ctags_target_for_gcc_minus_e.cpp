# 1 "d:\\Arduino\\OLED Sample\\app.ino"
# 1 "d:\\Arduino\\OLED Sample\\app.ino"
# 2 "d:\\Arduino\\OLED Sample\\app.ino" 2
# 3 "d:\\Arduino\\OLED Sample\\app.ino" 2




Adafruit_SSD1306 display(-1); // reset pin





void setup() {
  // initialize and clear display
  display.begin(0x2, 0x3C /* Địa chỉ của oled*/);
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, 1);
  display.drawPixel(127, 0, 1);
  display.drawPixel(0, 63, 1);
  display.drawPixel(127, 63, 1);

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(27,30);
  display.print("Hello, world!");

  // update display with all of the above graphics
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
