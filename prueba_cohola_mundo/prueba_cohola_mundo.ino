#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  delay(5000);
}

void loop() {
  Keyboard.println("hola mundo");
  delay(1000);


  
}
