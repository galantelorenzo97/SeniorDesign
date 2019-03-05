#include <Servo.h>

Servo esc0;
Servo esc1;
Servo esc2;
Servo esc3;
int throttle = 0;

void setup()
{
esc0.attach(PIN_A0);
esc1.attach(PIN_A1);
esc2.attach(PIN_A2);
esc3.attach(PIN_A3);
esc0.write(250);
esc1.write(250);
esc2.write(250);
esc3.write(250);
delay(4000);
esc0.write(25);
esc1.write(25);
esc2.write(25);
esc3.write(25);
delay(5000);
}

void loop()
{
esc0.write(40);
esc1.write(40);
esc2.write(40);
esc3.write(40);
delay(3000);
esc0.write(150);
esc1.write(150);
esc2.write(150);
esc3.write(150);
delay(6000);
}
