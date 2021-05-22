#include <Servo.h>
#include <LiquidCrystal_I2C.h> 

 LiquidCrystal_I2C lcd(0x3F, 16, 2);

 #define SERVO_PIN 9
 Servo gServo;
 void setup() 
{
  Serial.begin(9600);
  
  lcd.init();
  //lcd.begin();
  gServo.attach(SERVO_PIN); }
 void loop()
 { 
gServo.write(0); 
Serial.println(0);
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("0  ");
 delay(1000);
 gServo.write(90); 
Serial.println(90); 
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("90  ");

delay(1000);
 gServo.write(180); 
Serial.println(180);
lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("180  ");

delay(1000); }
