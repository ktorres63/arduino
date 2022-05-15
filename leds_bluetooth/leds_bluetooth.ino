#include <SoftwareSerial.h>

SoftwareSerial miBT(7, 8); // RX(recepcion) , TX (transmission)
                           //TX de modulo a RX(7), RX de modulo a Tx(8)
int led1 = 2;
int led2 = 3;
int led3 = 4;



char myChar;
void setup() {
  Serial.begin(9600);
  Serial.println("mon serie");

  miBT.begin(9600);
  miBT.println("CONEXION EXITOSA");

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);



}

void loop() {
  if (miBT.available()) {
    myChar = miBT.read();

    switch (myChar) {
      case 'a':
        digitalWrite(led1, HIGH);
        break;

      case 'A':
        digitalWrite(led1, LOW);
        break;


      case 'b':
        digitalWrite(led2, HIGH);
        break;

      case 'B':
        digitalWrite(led2, LOW);
        break;

      case 'c':
        digitalWrite(led3, HIGH);
        break;

      case 'C':
        digitalWrite(led3, LOW);
        break;


      case 'd':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        break;

      case 'D':
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        break;

    


    }

  }

}
