int boton =2;

int led = 8;
volatile int cont = 1000; 

void setup() {
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(boton),sensor,RISING);

}

void loop() {
  digitalWrite(led,HIGH);
  delay(cont);
  digitalWrite(led,LOW);
  if(cont < 100){
    cont = 1000;
  }
  
}
void sensor(){
  cont = cont -100;
}
