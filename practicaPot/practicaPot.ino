//CODIGO UTILIZACION DEL POTENCIOMETRO
int pot =A0;
int valor;
int led=8;
void setup() {
  Serial.begin(9600);
  pinMode (pot,INPUT);
  pinMode (led,OUTPUT);

}

void loop() {

  valor=analogRead(pot);
  Serial.println(valor);
  if(valor<=100){
    digitalWrite(led,HIGH);
  }
  if(valor >300 && valor <500){
    digitalWrite(led,LOW);
  }
  if(valor >900){
    digitalWrite(led,HIGH);
  }

}
