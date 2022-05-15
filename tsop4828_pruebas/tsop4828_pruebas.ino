#include <IRremote.h>
int led = 13;
int RECV_PIN = 11;

IRrecv ir(RECV_PIN);

decode_results resultado;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  ir.enableIRIn();
}

void loop() {
  if (ir.decode(&resultado)) {
    Serial.println(resultado.value);
    delay(200);
    ir.resume();

    if(resultado.value == 16724175){
      digitalWrite(13,HIGH);
    }
    else if(resultado.value == 16711935){
      digitalWrite(13,LOW);
    }
  
  }

}
