# 1 "d:\\Arduino\\OLED Sample\\app.ino"
# 1 "d:\\Arduino\\OLED Sample\\app.ino"
# 2 "d:\\Arduino\\OLED Sample\\app.ino" 2
# 3 "d:\\Arduino\\OLED Sample\\app.ino" 2
# 4 "d:\\Arduino\\OLED Sample\\app.ino" 2
# 5 "d:\\Arduino\\OLED Sample\\app.ino" 2


Adafruit_SSD1306 display(4);





void setup()
{
    display.begin(0x2, 0x3C); /* Initialize display with address 0x3C */
    display.clearDisplay(); /* Clear display */
    // display.setCursor(15, 5);                  /* Set x,y coordinates */
    // display.setTextSize(1);                    /* Select font size of text. Increases with size of argument. */
    // display.setTextColor(WHITE);               /* Color of text*/
    // display.println("ElectronicWings");        /* Text to be displayed */
    // display.display();
    // delay(500);
    // /* Draw rectangle with round edges. Parameters (x_co-ord,y-co-ord,width,height,color) */
    // display.drawRoundRect(5, 35, 35, 25, 1, WHITE);
    // /* Draw circle. Parameters (x_co-ord of origin,y-co-ord of origin,radius,color) */
    // display.drawCircle(65, 50, 12, WHITE);
    // /* Draw triangle. Parameters (x0,y0,x1,y1,x2,y2,width,color). (x0,y0), (x1,y1) and (x2,y2) are the co-ord of vertices of the triangle  */
    // display.drawTriangle(90, 60, 105, 35, 120, 60, WHITE);
    // display.display();
    // delay(1000);
    // display.clearDisplay();
    // /* Draw image. Parameters (x_co-ord, y_co-ord, name of array containing image, width of image in pixels, height in pixels, color) */
    // display.drawBitmap(0, 0, Arduino_Logo, 128, 64, WHITE);
    // display.display();
    // delay(1000);

    display.setTextSize(1);
    display.setTextColor(1);
    display.println("Hello world");
    display.display();
}

void loop()
{
}
