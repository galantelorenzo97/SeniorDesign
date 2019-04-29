#include <Servo.h>

Servo ESC;
Servo ESC1;
Servo ESC2;
Servo ESC3;
int val;
int potValue;
int adjPower;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  ESC.attach(9, 1000, 2000);
  ESC1.attach(10, 1000, 2000);
  ESC2.attach(11, 1000, 2000);
  ESC3.attach(12, 1000, 2000);
}

void loop() {
  val = pulseIn(2, HIGH, 100000000000000); 
  adjPower = map(val, 995, 2000, 995, 1400);
  potValue = map(adjPower, 995, 1400, 0, 180);
  Serial.print(val);
  Serial.print(" ");
  Serial.print(adjPower);
  Serial.print(" ");
  Serial.println(potValue);
  ESC.write(potValue);
  ESC1.write(potValue);
  ESC2.write(potValue);
  ESC3.write(potValue);
}
