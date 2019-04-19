int val = 0;
int timeBetw = 0;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  //while (! Serial);
}

void loop() {
  analogWrite(3, 250);
  val = pulseIn(2, HIGH, 100000000000000);
  timeBetw = pulseIn(2, LOW, 100000000000000);
  if (Serial.available())
  {
    if (val > 0)
    {
      Serial.print(val);
      Serial.print(" ");
      Serial.println(timeBetw);
    }
  }
}
