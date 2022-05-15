#include <Servo.h>
#include<NewPing.h>

int TRIG = 7;
int ECO = 6;
int DISTMAX = 200;

unsigned int tmp;
unsigned int tmp1;
unsigned int tmp2;

NewPing sonar(TRIG, ECO, DISTMAX);

Servo servobar;
void setup() {
  servobar.attach(4);
  Serial.begin(9600);

}

void loop() {
  servobar.write(90);
  delay(1000);
  tmp = sonar.ping_cm();

  Serial.print(" Ping central: ");
  Serial.println(tmp);
  delay(1000);

  servobar.write(0);
  delay(1000);

  tmp1 = sonar.ping();
  Serial.print(" ping izquierda: ");
  Serial.print(tmp1);
  delay(1000);

  servobar.write(180);
  delay(1000);

  tmp2= sonar.ping_cm();
  Serial.print(" Ping derecha: ");
  Serial.print(tmp2);
  delay(1000);
  
}
