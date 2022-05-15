#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 10); //RX|TX
// TX (hm-10)----- pin 11(arduino)
// RX (hm-10)------pin 10(arduino)


void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600); // default baud rate
  Serial.println("AT commands: ");
}

void loop(){
  //read from the HM-10 and print in the Serial
  if(BTSerial.available())
    Serial.write(BTSerial.read());
    
  //read from the Serial and print to the HM-10
  if(Serial.available())
    BTSerial.write(Serial.read());
}
