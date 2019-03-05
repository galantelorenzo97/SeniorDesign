//#include <bluefruit.h>

//BLEDis bledis;
//BLEHidAdafruit blehid;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_A0, OUTPUT);
  pinMode(PIN_A1, OUTPUT);
  pinMode(PIN_A2, OUTPUT);
  pinMode(PIN_A3, OUTPUT);

  //Start Drone setup
  setDrone();
  //Bluetooth nonsense
 /* Bluefruit.begin();
  Bluefruit.setTxPower(4);
  Bluefruit.setName("Team7_Drone");

  bledis.setManufacturer("Adafruit Industries");
  bledis.setModel("Bluefruit Feather 52");
  bledis.begin();

  blehid.begin();

  startAdv();
  */
}

void setDrone(void)
{
  Serial.println("Setting Drone...");
  analogWrite(PIN_A0, 250);
  analogWrite(PIN_A1, 250);
  analogWrite(PIN_A2, 250);
  analogWrite(PIN_A3, 250);
  delay(5000);
  analogWrite(PIN_A0, 50);
  analogWrite(PIN_A1, 50);
  analogWrite(PIN_A2, 50);
  analogWrite(PIN_A3, 50);
  //delay(1000);
}

/*void startAdv(void)
{
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);

  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for the dev name in the advertising packet
  Bluefruit.Advertising.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html   
   */
 // Bluefruit.Advertising.restartOnDisconnect(true);
 // Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
 // Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
//  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
//}

void loop() {
  Serial.println("Starting drone run: FULL throttle for 30 seconds.");
  analogWrite(PIN_A0, 250);
  analogWrite(PIN_A1, 250);
  analogWrite(PIN_A2, 250);
  analogWrite(PIN_A3, 250);
  delay(30000);
  Serial.println("Test complete");
    
  /*analogWrite(PIN_A0, 150);
  delay(500);
  analogWrite(PIN_A0, 200);
  delay(500);
  analogWrite(PIN_A0, 255);
  delay(500);
*/
}
