char tecla;
void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    tecla = Serial.read();
    if (tecla == 'a') {
      Serial.println(tecla);

      digitalWrite(8, HIGH);
    }
    if (tecla == 'o') {
      Serial.println(tecla);
      digitalWrite(8, LOW);



    }


  }


}
