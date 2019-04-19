#include <Servo.h>
Servo esc0, esc1, esc2, esc3;

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
delay(2500);
esc0.write(0);
esc1.write(0);
esc2.write(0);
esc3.write(0);
delay(2500);
esc0.write(250);
esc1.write(250);
esc2.write(250);
esc3.write(250);
delay(7500);
esc0.write(0);
esc1.write(0);
delay(1000);
esc0.write(250);
esc1.write(250);
delay(5000);
}

void loop() {

}
