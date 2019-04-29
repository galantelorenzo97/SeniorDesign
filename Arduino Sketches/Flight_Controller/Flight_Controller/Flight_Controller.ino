#include <Servo.h>

Servo FrontCW;
Servo FrontCCW;
Servo RearCW;
Servo RearCCW;
int valCH1;
int valCH2;
int valCH3;
int valCH4;
int potValueCH3;
int adjPowerCH3;

int CH1_roll = 11;
int CH2_pitch = 10;
int CH3_throttle = 9;
int CH4_yaw = 8;


void setup() {
  Serial.begin(9600);
  pinMode(CH1_roll, INPUT);
  pinMode(CH2_pitch, INPUT);
  pinMode(CH3_throttle, INPUT);
  pinMode(CH4_yaw, INPUT);
  FrontCW.attach(7, 1000, 2000); //A1
  FrontCCW.attach(4, 1000, 2000); //C1
  RearCW.attach(5, 1000, 2000); //B1
  RearCCW.attach(6, 1000, 2000); //D1
}

void loop() {
  /******************************
     MEASURE ALL WIDTH PULSES
  */
  valCH1 = pulseIn(CH1_roll, HIGH, 100000000);
  valCH2 = pulseIn(CH2_pitch, HIGH, 100000000);
  valCH3 = pulseIn(CH3_throttle, HIGH, 100000000);
  valCH4 = pulseIn(CH4_yaw, HIGH, 100000000);

  /********************************
     Convert Raw readings to angles for the motors (ONLY CH3 might
     be necessary) 4/28/19 7:10 PM
  */

  // CH3- throttle controls
  adjPowerCH3 = map(valCH3, 995, 2000, 995, 1400); //Convert Raw Reading
  potValueCH3 = map(adjPowerCH3, 995, 1400, 0, 180); //Convert to Write Angle

  /*
    Serial.print(val);
    Serial.print(" ");
    Serial.print(adjPower);
    Serial.print(" ");
    Serial.println(potValue);
  */

  /****************************
    WRITE THROTTLE VALUES
  ******************************/

  FrontCW.write(potValueCH3);
  FrontCCW.write(potValueCH3);
  RearCW.write(potValueCH3);
  RearCCW.write(potValueCH3);


  //CCW Rotation control (aka LEFT)
  while (valCH4 < 1400)
  {
    FrontCW.write(minLimit(potValueCH3 - 20, 40));
    FrontCCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCW.write(minLimit(potValueCH3 - 20, 40));
    RearCCW.write(maxLimit(potValueCH3 + 20, 180));
    valCH4 = pulseIn(CH4_yaw, HIGH, 100000000);
  }

  //CW Rotation control (aka RIGHT)
  while (valCH4 > 1600)
  {
    FrontCW.write(maxLimit(potValueCH3 + 20, 180));
    FrontCCW.write(minLimit(potValueCH3 - 20, 40));
    RearCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCCW.write(minLimit(potValueCH3 - 20, 40));
    valCH4 = pulseIn(CH4_yaw, HIGH, 100000000);
  }

  //Nose up controls (aka Back)
  while (valCH2 < 1400)
  {
    FrontCW.write(maxLimit(potValueCH3 + 20, 180));
    FrontCCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCW.write(minLimit(potValueCH3 - 20, 40));
    RearCCW.write(minLimit(potValueCH3 - 20, 40));
    valCH2 = pulseIn(CH2_pitch, HIGH, 100000000);
  }

  //Nose down controls (aka Forwards)
  while (valCH2 > 1600)
  {
    FrontCW.write(minLimit(potValueCH3 - 20, 40));
    FrontCCW.write(minLimit(potValueCH3 - 20, 40));
    RearCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCCW.write(maxLimit(potValueCH3 + 20, 180));
    valCH2 = pulseIn(CH2_pitch, HIGH, 100000000);
  }

  //Tilt controls left (aka BANK LEFT)
  while (valCH1 < 1400)
  {
    FrontCW.write(minLimit(potValueCH3 - 20, 40));
    FrontCCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCW.write(maxLimit(potValueCH3 + 20, 180));
    RearCCW.write(minLimit(potValueCH3 - 20, 40));
    valCH1 = pulseIn(CH1_roll, HIGH, 100000000);  
  }

  //Tilt controls left (aka BANK LEFT)
  while (valCH1 > 1600)
  {
    FrontCW.write(maxLimit(potValueCH3 + 20, 180));
    FrontCCW.write(minLimit(potValueCH3 - 20, 40));
    RearCW.write(minLimit(potValueCH3 - 20, 40));
    RearCCW.write(maxLimit(potValueCH3 + 20, 180));
    valCH1 = pulseIn(CH1_roll, HIGH, 100000000);  
  }
}

int maxLimit(int toLimit, int maxLimitSet)
{
  if (toLimit > maxLimitSet)
  {
    return maxLimitSet;
  }
  return toLimit;
}

int minLimit(int toLimit, int minLimitSet)
{
  if (toLimit < minLimitSet)
  {
    return minLimitSet;
  }
  return toLimit;
}
