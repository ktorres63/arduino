#include <IRremote.h>
//TSOP
int RECV_PIN = 11;

IRrecv ir(RECV_PIN);
decode_results resultado;

//MOTOR 1
int IN1 = 2;
int IN2 = 3;
int ENA = 5;

//MOTOR 2
int IN3 = 6;
int IN4 = 7;
int ENB = 9;


void setup() {
  Serial.begin(9600);
  ir.enableIRIn();

  //MOTOR 1
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  //MOTOR 2
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void loop() {
  if (ir.decode(&resultado)) {
    Serial.println(resultado.value);
    delay(200);
    ir.resume();

    // ADELANTE
    if (resultado.value == 16718055 ) {

      horario(IN1, IN2, ENA);           // MOTOR A
      antihorario(IN3, IN4, ENB);      // MOTOR B
      delay(500);
      apagar(ENA);
      apagar(ENB);

    }

    // ATRAS
    else if (resultado.value == 16730805 ) {

      antihorario(IN1, IN2, ENA);
      horario(IN3, IN4, ENB);
      delay(500);
      apagar(ENA);
      apagar(ENB);
    }

    //GIRO D
    else if (resultado.value == 16734885 ) {
      horario(IN1, IN2, ENA);
      apagar(ENB);
      delay(200);
      apagar(ENA);

    }
    //GIRO I
    else if (resultado.value == 16716015 ) {

      antihorario(IN3, IN4, ENB);
      apagar(ENA);
      delay(200);
      apagar(ENB);
    }

    //PARAR
    else if (resultado.value == 16726215 ) {
      apagar(ENA);
      apagar(ENB);

    }
  }

}
//sentido en que gira el motor
void horario( int in1, int in2, int ena) {
  digitalWrite(ena, HIGH);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);

}
void antihorario( int in1, int in2, int ena) {
  digitalWrite(ena, HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);

}
void apagar( int ena) {
  digitalWrite(ena, LOW);
}
void encender(int ena) {
  digitalWrite(ena, HIGH);
}
