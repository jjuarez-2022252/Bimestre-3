/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Alvaro Marroquin , Javier Juarez
   Profe Alejandro
   Carnet: 2022375
   Proyecto: cinta transportadora
*/
#include <Servo.h>

#define ch_LDR    A0
#define led_Azul  2
#define led_Verde 4
#define led_Rojo  5
#define sen       6
int avoid;
int resultado_azul, resultado_rojo, resultado_verde;
int resultado;
int tol = 8;
Servo myservo;
void funcion_ISR_falling(void);
void funcion_ISR_rising(void);

void setup() {

  Serial.begin(9600);
  myservo.attach(3);
  myservo.write(0);
  pinMode(5, OUTPUT);
  pinMode(6 , INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);

 
}


void loop() {
  bool sen_LEER = digitalRead(sen);
 
  if (sen_LEER == HIGH) {
    myservo.write(90);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(2);

    digitalWrite(2, LOW);
    delay(2);


    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(2);

    digitalWrite(4, LOW);
    delay(2);

    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    delay(2);

    digitalWrite(5, LOW);
    delay(2);

    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    delay(2);

  }
  if (sen_LEER == LOW) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(led_Rojo, HIGH);
    delay(150);
    digitalWrite(led_Rojo, LOW);
    delay(150);
    digitalWrite(led_Verde, HIGH);
    delay(150);
    digitalWrite(led_Verde, LOW);
    delay(150);
   
    digitalWrite(led_Azul, HIGH);
    delay(150);
    digitalWrite(led_Azul, LOW);
    delay(150);


   
    resultado = analogRead(ch_LDR);
    resultado_rojo = map(resultado, 0, 1023, 0, 1023);
    Serial.print("R = ");
    Serial.println(resultado_rojo);
   



   
    resultado = analogRead(ch_LDR);
    resultado_verde = map(resultado, 0, 1023, 0, 1023);
    Serial.print("G = ");
    Serial.println(resultado_verde);
   




   
    resultado = analogRead(ch_LDR);
    resultado_azul = map(resultado, 0, 1023, 0, 1023);
    Serial.print("B = ");
    Serial.println(resultado_azul);
   


    myservo.write(0);

    if (led_Rojo > led_Verde && led_Rojo > led_Azul)
    {
      myservo.write(0);
     
    }
    if (led_Verde > led_Rojo && led_Verde > led_Azul)
    {
      myservo.write(90);
    }
    if (led_Azul > led_Rojo && led_Azul > led_Verde)
    {
      myservo.write(0);
    }
  }




}
