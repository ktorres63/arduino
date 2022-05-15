#include <LiquidCrystal.h>
int pot = A0;
int valor;
LiquidCrystal lcd (6, 7, 8, 9, 10, 11, 12);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.write("volumen");
  lcd.setCursor(0, 1);
  lcd.write("00");

            pinMode(pot, INPUT);

}

void loop() {
  valor = analogRead(pot);
  Serial.println(valor);
  if (valor <= 100) {
    lcd.setCursor(0, 0);
    lcd.write("vol");
    lcd.setCursor(0, 1);
    lcd.write("0");
  }
  else {
    if (valor >= 101 && valor <= 200) {
      lcd.setCursor(0,0);
      lcd.write("VOLUMEN: ");
      lcd.setCursor(0, 1);
      lcd.write("10");
    }
    else {
      if (valor >= 210 && valor <= 300) {
        lcd.setCursor(0,0);
        lcd.write("VOLUMEN: ");
        lcd.setCursor(0,1);
        lcd.write("20");
      }
    }
  }
}
