int ledPin = 16; // set chân pin cho led. 
int ledState = LOW;
int btnPin = 0;  // set chân pin cho nút nhấn. trên board arduino wifi uno mặc định nút nhấn là GPIO0


void blink() {
  if(ledState == LOW){
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  
  digitalWrite(ledPin, ledState);
  Serial.println("Pressed, Value =" + String(ledState));
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
  pinMode(btnPin, INPUT_PULLUP);
  attachInterrupt(btnPin, blink, FALLING);  
  Serial.begin(115200); // attach serial port
}

void loop() {

}
