#include <SoftwareSerial.h>

SoftwareSerial sw(2,3);
void setup() {
  Serial.begin(9600);
  sw.begin(9600);
  
}

void loop() {
  if(Serial.available()>0){

    char c =Serial.read();
    sw.print(c);
  }
  if(sw.available()>0){
    char c = sw.read();
    Serial.print(c);
  }
}
