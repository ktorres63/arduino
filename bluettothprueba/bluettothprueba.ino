#include <SoftwareSerial.h>

SoftwareSerial miBT(7,8);

char myChar;
void setup() {
  Serial.begin(9600);
  Serial.println("Listo");
   
  miBT.begin(9600);
  miBT.println("hola mundo");
   
    
}

void loop() {
  while(miBT.available()){
    myChar = miBT.read();
  }
  while(Serial.available()){
    myChar = Serial.read();
    miBT.println(myChar);
    
  }
  
}
