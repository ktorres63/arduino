int SENSOR = 0;
int LED = 3;
int VALOR;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  //ENTRADAS ANALOGICAS NO REQUIERES INICIALIZACION
  pinMode(SENSOR, INPUT);
}

void loop() {
  VALOR = analogRead(SENSOR);
  Serial.println(VALOR);
  delay(1000);

  if (VALOR < 200) {
    digitalWrite(LED,HIGH);
    delay(1000);

  }
  else{
    digitalWrite(LED,LOW);
  }
}
