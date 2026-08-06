#include <Servo.h>

Servo servo;

const int trig = 9;
const int echo = 10;
const int led = 7;
const int servoPin = 3;

long time;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);

  servo.attach(servoPin);
  servo.write(0);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    servo.write(90);
    digitalWrite(led, HIGH);
  } else {
    servo.write(0);
    digitalWrite(led, LOW);
  }

  delay(100);
}