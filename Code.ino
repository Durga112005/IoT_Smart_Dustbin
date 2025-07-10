#include <Servo.h>

Servo lidServo;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  lidServo.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lidServo.write(0); // lid closed
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) {
    lidServo.write(90); // Open lid
    delay(3000);
    lidServo.write(0);  // Close lid
  }

  delay(500);
}