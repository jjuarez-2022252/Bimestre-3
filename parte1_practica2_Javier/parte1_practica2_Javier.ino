/*
FUNDACION KINAL
CENTRO: Educativo Tecnico Laboral Kinal
Perito en Electronica 
Quinto Perito
SECCION: A
CURSO: Taller de Electronica Digital y Reparacion de Computadoras 
Proyecto: Control de Brillo de un Led
ALUMNOS: Jose Javier Juarez Rivera
CARNET: 2022252
*/

#define led0 3
#define pot A0

int intensidad, brillo;

void setup() {
  pinMode(led0, OUTPUT);
}

void loop() {
     intensidad=analogRead(pot);
  
     //Map de los valores del potenciometro
     brillo=map(intensidad, 0, 1023, 0, 255);

     analogWrite(led0, brillo);

}
