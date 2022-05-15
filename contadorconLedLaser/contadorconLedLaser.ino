int laser = 13;
int ldr = A0;
int contador = 0;
int valor = 0;
int led = 4;
void setup() {
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  digitalWrite(laser, HIGH);
  valor = analogRead(ldr);

  delay(1000);
  Serial.println(contador);


  if (valor <= 800) {
    contador++;
  
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
}
