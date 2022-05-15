//pag 166
int maximo =255;
void setup() {
  pinMode(5,OUTPUT);
  
}

void loop() {
  randomSeed( millis());
  analogWrite(5,random(maximo));
  delay(200);
  

}
void brillo(){
  for(int i=0;i<=255;i++){
    analogWrite(5,i);
    delay(500);
  }
//  for(int i=255;i<255;i--){
//    analogWrite(5,i);
//    delay(500);
//  }
}
