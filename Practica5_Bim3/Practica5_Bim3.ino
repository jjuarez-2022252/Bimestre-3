/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Jose Javier Juarez
   Profe Alejandro
   Carnet: 2022252
   Proyecto: Matriz Led
*/
#include <Ticker.h>
#include <LedControl.h>

//Directivas de Preprocesado
#define sensor_gas A0
#define dataPin0   13   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 11   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  10   //pin 10 conectado al pin de carga del max7219.

//Funciones
void medicion(void);
void fuegoo(void);
//Variables
int i, gas, conver, seg;
unsigned long update_delay = 850;

//Constructores
Ticker mediciones(medicion, 2000);
LedControl matriz = LedControl(dataPin0 , dataClock0, dataLoad0, 1); // Los numeros se refieren a que pin de arduino tienes en cada uno de los terminales
/* 11 para el DIN, 13 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/

//Animaciones
byte Copo1[8] =
{
  B10011001,
  B01011010,
  B00111100,
  B11100111,
  B11100111,
  B00111100,
  B01011010,
  B10011001
};
byte Fuego1[8] =
{
  B00000000,
  B00001100,
  B00101100,
  B00111110,
  B10111111,
  B10111111,
  B11111111,
  B11111111
};

void setup() {
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  Serial.begin(9600);
  pinMode(sensor_gas, INPUT);
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8); // La valores estan entre 1 y 15
  matriz.clearDisplay(0);
  mediciones.start();
}

void loop() {
  mediciones.update();
 
  if (conver > 40 ) {
  
    Serial.println("Hay Fuego ");
    if(seg==0){
      fuegoo();
      
      
    }
    if(seg==1){
     for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, Fuego1[i]);
    } 
    }
    //fuego
}
else{
  seg=0;
   for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, Copo1[i]);

    }
}

delay(1000);
}

void medicion(void) {

  gas = analogRead(A0);
  conver = map(gas, 0, 1023, 0, 100);
  Serial.println(conver);
}
void fuegoo()
{
for(int i=0; i<8;i++)
{
matriz.setRow(0,i,Fuego1[i]);
}
delay(1000);  
matriz.clearDisplay(0);
delay(1000);
for(int i=0; i<8;i++)
{
matriz.setRow(0,i,Fuego1[i]);
}
delay(1000);  
matriz.clearDisplay(0);
delay(1000);
for(int i=0; i<8;i++)
{
matriz.setRow(0,i,Fuego1[i]);
}
delay(1000);  
matriz.clearDisplay(0);
delay(1000);
for(int i=0; i<8;i++)
{
matriz.setRow(0,i,Fuego1[i]);
}
delay(1000);  
matriz.clearDisplay(0);
delay(1000);
for(int i=0; i<8;i++)
{
matriz.setRow(0,i,Fuego1[i]);
}
delay(1000);  
seg=1;
}
