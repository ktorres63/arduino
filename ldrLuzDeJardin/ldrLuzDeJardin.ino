//int ldr = A0;
int sensibilidad =200;

int luz2 = 3;
int sensor=0;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(luz2, OUTPUT);

  //pinMode(ldr, INPUT); // entradas analogicas no neceistan ser declaradas como entrada
}

void loop() {
  val = analogRead(sensor);
  Serial.println(val);
  if (val < sensibilidad) {
    digitalWrite(luz2, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(luz2, LOW);
    //delay(1000);
  }
}
