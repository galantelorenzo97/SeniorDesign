void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  for(int i=0; i < 250; i++)
  {
    Serial.println(i);
    lowThrottlePulse(2);
  }
  Serial.println("LOW THROTTLE COMPLETE");
  for(int i=0; i < 100; i++)
  {
    highThrottlePulse(2);
  }
  Serial.println("HIGH THROTTLE COMPLETE");
}

void highThrottlePulse(int pinHigh) {
  analogWrite(pinHigh,255);
  delay(2);
  analogWrite(pinHigh,0);
  delay(18);
  
}

void lowThrottlePulse(int pinLow) {
  analogWrite(pinLow,150);
  delay(1);
  analogWrite(pinLow,0);
  delay(19);
}
