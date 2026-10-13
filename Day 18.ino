#include <Servo.h>   // loads the servo library

Servo myServo;
const int buttonPin = 2;
const int buzzerPin = 8;
const int servoPin = 9;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // button reads LOW when pressed
  pinMode(buzzerPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);                  // default position
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {   // trigger: button pressed
    myServo.write(90);                   // move servo to 90°
    digitalWrite(buzzerPin, HIGH);       // sound buzzer
    delay(500);                          // for 500 ms
    digitalWrite(buzzerPin, LOW);        // buzzer off
    delay(500);                          // brief wait
    myServo.write(0);                    // return to default
  }
}
