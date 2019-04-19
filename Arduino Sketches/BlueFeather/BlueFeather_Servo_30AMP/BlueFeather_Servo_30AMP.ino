#include <Servo.h>

Servo esc0;
Servo esc1;
Servo esc2;
Servo esc3;
int throttle = 0;

void setup()
{
esc0.attach(2);
pinMode(PIN_A1, OUTPUT);

//esc1.attach(PIN_A1);
esc2.attach(PIN_A2);
esc3.attach(PIN_A3);
//delay(5000);
esc0.write(250);
//esc1.write(250);
esc2.write(250);
esc3.write(250);
delay(5000);
esc0.write(25);
//esc1.write(0);
esc2.write(25);
esc3.write(25);
delay(5000);
}

void loop()
{
delay(2000);
//esc0.write(200);
//esc1.write(10);
analogWrite(PIN_A1, 10);
delay(30000);
//esc2.write(100);
//esc3.write(100);
delay(4000);
esc0.write(150);
//esc1.write(125);
analogWrite(PIN_A1, 125);
delay(60000);
//esc2.write(150);
//esc3.write(150);
}
