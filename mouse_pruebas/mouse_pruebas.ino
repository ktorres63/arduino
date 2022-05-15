#include <MouseTo.h>
const int pulsador = 2;
const int led = 4;

int estadoB = 0; // variable para leer el estado boton
int variable_estadoB = 0; // variable para guardar el estado boton

long valor1, valor2;

void setup() {
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(led, OUTPUT);
  Mouse.begin();
}

void loop() {
  estadoB = digitalRead(pulsador);
  valor1 = analogRead(A0);
  valor2 = analogRead(A1);

  if (estadoB == LOW) {
    variable_estadoB = !variable_estadoB;
    delay(300);

  }
  else if (variable_estadoB == HIGH) {

    digitalWrite(led, HIGH);
    Mouse.move(10,2, 0);
   


  }
  else {
    digitalWrite(led, LOW);

  }
}
