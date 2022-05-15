# include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte pinesFilas[FILAS] = {9,8,7,6}; // CONECTADOS A ARDUINO
byte pinesColumnas[COLUMNAS] ={ 5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS);

char TECLA;
char CLAVE[7];
char CLAVE_MAESTRA[7]="123456";
byte indice =0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  TECLA = teclado.getKey();
  if(TECLA){  
    CLAVE[indice] = TECLA;
    indice++;;
    Serial.print(TECLA);
  }
  if( indice ==6){
    if(!strcmp(CLAVE, CLAVE_MAESTRA))
      Serial.println(" correcta");
    else
      Serial.println(" incorrecta");

    indice =0;
  }

}
