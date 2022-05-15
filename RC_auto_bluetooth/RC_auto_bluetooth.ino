#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
// hm 10   Arduino
// TX      2
// RX      3

//MOTOR 1
int IN1 = 13;
int IN2 = 12;
int ENA = 11;

//MOTOR 2
int IN3 = 4;
int IN4 = 5;
int ENB = 6;

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() {
  Dabble.processInput();
  Serial.print("keyPressed");

  if (GamePad.isUpPressed()) {
    Serial.print("UP");
    forward();
  }
  else if (GamePad.isDownPressed()) {
    Serial.print("DOWN");
    backward();
  }
  else if (GamePad.isLeftPressed()) {
    Serial.print("LEFT");
    left();
  }
  else if (GamePad.isRightPressed()) {
    Serial.print("RIGHT");
    right();
  }
  else {
    Serial.print("STOP");
    apagar(ENA);
    apagar(ENB);

  }

  Serial.print('\n');


}
void forward() {
  horario(IN1, IN2, ENA); //motor1
  antihorario(IN3, IN4, ENB); //motor2
}
void backward() {
  antihorario(IN1, IN2, ENA);
  horario(IN3, IN4, ENB);
}

void left() {
  horario(IN1, IN2, ENA);
  apagar(ENB);

}
void right() {
  antihorario(IN3, IN4, ENB);
  apagar(ENA);
}

void antihorario( int in1, int in2, int ena) {
  digitalWrite(ena, HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);

}

void horario( int in1, int in2, int ena) {
  digitalWrite(ena, HIGH);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);

}
void apagar( int ena) {
  digitalWrite(ena, LOW);
}
