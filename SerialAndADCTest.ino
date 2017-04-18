const int potIn = A7;
char inbyte;

int adcRead;
char* voltage;
float volts;
float pi = 3.14;
int id = 1;
int battery = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  adcRead = ADCReading(potIn); //Get ADC reading
  //voltage = voltageList(adcRead);  //Convert int to string
  volts = ADCVoltage(adcRead);
  sendSensorInfo(volts, id, battery);

  delay(2000); //Wait 2 seconds between reading
}

int ADCReading(int port) {
  return analogRead(port);
}


float ADCVoltage(int ADCreading) {
  return (((float)ADCreading / 1023) * 5);
}
/*
char* voltageList(int ADCreading) {
  char *ret = malloc(sizeof(char) * 4);
  ret[0] = ((int)((ADCreading / 1023) * .5) % 10) + 0x30; //10s Place
  ret[1] = ((int)((ADCreading / 1023) *  5) % 10) + 0x30; //1s Place
  ret[2] = '.';
  ret[3] = ((int)((ADCreading / 1023) * 50) % 10) + 0x30; //Decimal value
  return ret;
}
*/
void sendSensorInfo(float temp, int id, int battery) {
  //Send the values we want to the HUB
  Serial.println('#'); //Start Transmission
  //Send the temperature data first
  /*
    for (int i = 0; i < 4; i++) {
    Serial.print(temp[i]);
    }
  */
  //Serial.print(adcRead);
  Serial.println(temp);
  //Send identification value
  Serial.println(id);
  //Send battery level value
  Serial.println(battery);

  Serial.println('~'); //Send Transmission
  delay(10);
}

void receiveID() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    id = Serial.read();
  }
}



