//Directivas de Procesador
#include <LiquidCrystal_I2C.h>
#define voltaje A0

//Variables
int Vcc = 5;
int R2 = 10000;
float R1 = 0;
float Vout = 0;
float lectura = 0;
float valor = 0;
float conver = 0;

//Constructor
LiquidCrystal_I2C lcd(0x27,16,2);

//Funciones
void conversion();

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
 conversion();
}

void conversion(){
  lectura = analogRead(voltaje);
   
  //Realizamos la conversion de esa lectura
  conver = lectura * Vcc;
  Vout = conver / 1023;

  //Realizamos la operación necesaria para obtener el valor de R1
  valor = (Vcc - Vout)/Vout;
  R1 = R2 * valor; 
  R1=R1+10;
  
 if(lectura){
  lcd.setCursor(0,0);
  lcd.print("el valor es:");
  lcd.setCursor(10,1);
  lcd.print("ohms");
  lcd.setCursor(2,1);
  lcd.print(R1);
 }
if(!lectura){
  lcd.setCursor(0,0);
  lcd.print("sin resistencia");
}
 }    
 
