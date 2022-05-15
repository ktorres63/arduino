int buzzer = A0;
int boton =7;
int led=13;
int vb=0;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(boton,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  vb= digitalRead(boton);
  if(vb==HIGH){
    for( int i=0;i<10;i++){
      delay(220);
      tone(buzzer,220,100);
      digitalWrite(led, HIGH);
      delay(220);
      noTone(buzzer);
      digitalWrite(led,LOW);








      
    }
  }
  
}
