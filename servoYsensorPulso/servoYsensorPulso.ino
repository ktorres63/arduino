#include <Servo.h>
Servo propulsion;
int bumper=8;
int dato=0;
//int led=13;

void setup() {
  Serial.begin(9600);
  pinMode(bumper,INPUT);
  propulsion.attach(11);
  //pinMode(led,OUTPUT);
  pinMode(bumper,INPUT);
}

void loop() {
  Serial.println(dato);
  dato=digitalRead(bumper);
  if(dato==1){
    propulsion.write(20);
    //digitalWrite(led,HIGH);
  }
  dato=digitalRead(bumper);

  if(dato==0){
    propulsion.write(90);
    //digitalWrite(led,LOW);
  }

}
