# include <Keypad.h>
# include <Servo.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte pinesFilas[FILAS] = {9, 8, 7, 6}; // CONECTADOS A ARDUINO
byte pinesColumnas[COLUMNAS] = { 5, 4, 3, 2};

char i[4] = {0, 0, 0, 0}; // almacena la combinacion de nums

char key = 0; // guarda los chars enviados
int j = 0;
int cont = 0;

int led = 12;
Servo motor;

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  motor.attach(13);
}

void loop() {
  while ( cont < 4) {
    key = teclado.getKey();
    i[j] = key;

    if (key) {
      Serial.println(i[0]);
      Serial.println(i[1]);
      Serial.println(i[2]);
      Serial.println(i[3]);
      j++;
      cont++;

    }
    //CLAVE SERVOMOTOR
    if (i[0] == '1' && i[1] == '2' && i[2] == '3' && i[3] == '4') {
      motor.write(180);
      i[0] = 0;
      i[1] = 0;
      i[2] = 0;
      i[3] = 0;
    }
    else {
      if (i[0] == '1' && i[1] == '2' && i[2] == '1' && i[3] == '2') {
        motor.write(90);
        i[0] = 0;
        i[1] = 0;
        i[2] = 0;
        i[3] = 0;
      }
    }
    //CLAVE LED
    if (i[0] == '1' && i[1] == '1' && i[2] == '1' && i[3] == '1') {
      digitalWrite(led, HIGH);
      i[0] = 0;
      i[1] = 0;
      i[2] = 0;
      i[3] = 0;
    }
    else {
      if (i[0] == '2' && i[1] == '2' && i[2] == '2' && i[3] == '2') {
        digitalWrite(led, LOW);
        i[0] = 0;
        i[1] = 0;
        i[2] = 0;
        i[3] = 0;
      }
    }
  }

  cont = 0;
  j = 0;
  key = 0;
}
