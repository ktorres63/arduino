
int PULSADOR = 2;
int led = 4;
int estado = 0;
int estadoLed = 0;
void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void loop() {
  estado = digitalRead(PULSADOR);
  if (estado == LOW) {
    estadoLed = digitalRead(4);
    digitalWrite(led, !estadoLed); // cambia el estado
    delay(1000);
  }
}
