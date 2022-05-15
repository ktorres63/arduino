#include <Keyboard.h>

int pulsador = 2;

void setup() {
  Keyboard.begin();
  delay(3000);
  
}

void loop() {
  if(digitalRead(pulsador)==HIGH){
    Keyboard.press(KEY_F1);
    delay(100);
    Keyboard.releaseAll();
  }
}
