int piezo = A0;

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  delay(320);
  tone(piezo, 320,100);
  delay(320);
  noTone(piezo);

}
