
int pin_rojo=13;
int pin_azul=12;

void setup() {
  pinMode(pin_rojo,OUTPUT);
  pinMode(pin_azul,OUTPUT);
  

}
void loop() {
  digitalWrite(pin_rojo,LOW);
  digitalWrite(pin_azul,LOW);

  digitalWrite(pin_rojo,HIGH);
  delay(1000);
  digitalWrite(pin_rojo,LOW);
  digitalWrite(pin_azul,HIGH);
  delay(1000);
  digitalWrite(pin_azul,LOW);
  delay(1000);
}
