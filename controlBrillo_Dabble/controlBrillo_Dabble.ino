
#define CUSTOM_SETTINGS
#define INCLUDE_LEDCONTROL_MODULE
#include <Dabble.h>

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);

}

void loop() {
  Dabble.processInput();          //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  
  Serial.print("Led:");
  Serial.print(LedControl.getpinNumber());
  Serial.print('\t');
  Serial.print("State:");          //0 means OFF, 1 means ON
  Serial.print(LedControl.getpinState());
  Serial.print('\t');
  Serial.print("Brightness:");
  Serial.println(LedControl.readBrightness());

}
