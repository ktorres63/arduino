int x;
int y;
int led_izq = 3;
int led_der = 5;
int led_arr = 9;
int led_abj = 6;
int pulsador = 10;
int led_sw = 11;
int sw;
void setup() {
  pinMode(led_izq, OUTPUT);
  pinMode(led_der, OUTPUT);
  pinMode(led_arr, OUTPUT);
  pinMode(led_abj, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
  
  //entradas analogicas no requieren inicializacion
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  sw = digitalRead(pulsador);

  
// X
  if (x >= 0 && x < 529)
    analogWrite(led_izq, map(x, 0, 490, 255, 0));
  else
    analogWrite(led_izq, 0);

  if (x > 531 && x <= 1023)
    analogWrite(led_der, map(x, 513, 1023, 0, 255));
  else
    analogWrite(led_der, 0);

// Y
  if (y >= 0 && y< 529)
    analogWrite(led_abj, map(y, 0, 490, 255, 0));
  else
    analogWrite(led_abj, 0);
    
  if (y > 531 && y<=1023)
    analogWrite(led_arr, map(y, 5130, 1023, 0, 255));
  else
    analogWrite(led_arr, 0);

  digitalWrite(led_sw,!sw);



}
