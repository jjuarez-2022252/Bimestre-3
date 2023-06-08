/*
FUNDACION KINAL
CENTRO: Educativo Tecnico Laboral Kinal
Perito en Electronica 
Quinto Perito
SECCION: A
CURSO: Taller de Electronica Digital y Reparacion de Computadoras 
Proyecto: Control de una Secuencia de colores
ALUMNOS: Jose Javier Juarez Rivera
CARNET: 2022252
*/

#define pot A0
#define ledr 9
#define ledg 10
#define ledb 11

int variacion,tiempo;
void setup() {
  pinMode(pot, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);

}

void loop() {
  //variacion= analogRead(pot);
  //Map de los valores del potenciometro
  tiempo=map(analogRead(pot), 0, 1023, 100, 1000);

  analogWrite(ledr, 174);
  analogWrite(ledg, 92);
  analogWrite(ledb, 230);
  delay(tiempo);

  analogWrite(ledr, 255);
  analogWrite(ledg, 255);
  analogWrite(ledb, 255);
  delay(tiempo);

  analogWrite(ledr, 0);
  analogWrite(ledg, 255);
  analogWrite(ledb, 255);
  delay(tiempo);

  analogWrite(ledr, 189);
  analogWrite(ledg, 174);
  analogWrite(ledb, 20);
  delay(tiempo);

  analogWrite(ledr, 225);
  analogWrite(ledg, 87);
  analogWrite(ledb, 35);
  delay(tiempo);
}
