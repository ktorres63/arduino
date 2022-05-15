#include <NewPing.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

int trig=9;
int eco=8;
int distmax=200;

int dist=0;
int led1=10;
int led2=11;

unsigned int tmp;
NewPing sensor(trig,eco,distmax);

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  lcd.begin(16,2);

}

void loop() {
  delay(200);
  tmp=sensor.ping();
  Serial.print("ping: ");
  Serial.print(tmp/US_ROUNDTRIP_CM);
  Serial.println("cm");
  dist= tmp/US_ROUNDTRIP_CM;

  if(dist <10) {
    
    
    digitalWrite( led1,HIGH);
    digitalWrite( led2,LOW);
    
    lcd.setCursor(0,0);
    lcd.print("plaza");
    lcd.setCursor(0,1);
    lcd.print("ocupada");
    
  }
  else {

    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
   
    lcd.setCursor(0,0);
    lcd.print("plaza");
    lcd.setCursor(0,1);
    lcd.print("libre");
    
  }
  

}
