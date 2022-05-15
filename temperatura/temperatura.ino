#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

float valor = 0;
int grados = 0;
int tmp = A0;
void setup() {
  Serial.begin(9600);
  pinMode( tmp, INPUT);
  lcd.begin(16, 2);


}

void loop() {
  valor= analogRead(tmp);
  grados = valor * 0.48828125;
  
  lcd.setCursor(0, 0);
  lcd.write("temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print(grados);
  lcd.setCursor(6, 1);
  lcd.write("grados ");
  delay(6000);

}
