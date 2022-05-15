int led =13;
int sensor = 8;
boolean estado=false;
int valor =0;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {

  valor=digitalRead(sensor);
  if(valor==HIGH){
    digitalWrite(led,HIGH);

    while(estado ==false){
      Serial.println("alarma");
      estado = true;
    }
  }
  else {
    digitalWrite(led,LOW);
    if(estado == true){
      estado=false;

    }
  }
}
