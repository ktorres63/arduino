int led =6;
int cny=7;
int valor=0;

void setup() {
  pinMode(led,OUTPUT);

  pinMode(cny, INPUT);
  Serial.begin(9600);
}

void loop() {
  valor=digitalRead(cny);
  digitalWrite(led,valor);
  Serial.println(valor);

}
