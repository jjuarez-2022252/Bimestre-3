//Directivas de Propocesador
#define btn_arriba 2 //pin 2 utilizado para una interrupción externa para rising
#define btn_abajo 3 //pin 3 utilizado para una interrupción externa para falling
#define A 4
#define B 5
#define C 6
#define D 7

#define A0 8
#define B0 9
#define C0 10
#define D0 11

//Funciones
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
void display_primero();
void display_segundo();

//Variables
volatile static bool f_print = false; //Variable booleana que me permite imprimir un texto en el Loop
int unidades = 0; ///variable que va de 0 - 9
int decenas = 0; ///variable que va de 0 - 5

void setup() {
    pinMode(btn_arriba, INPUT);
  pinMode(btn_abajo, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(B0, OUTPUT);
  pinMode(C0, OUTPUT);
  pinMode(D0, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(btn_arriba),funcion_ISR_rising,RISING); //Anclar la interrupcion del pin 9 a una funcion de ISR, disparado por el flanco
  attachInterrupt(digitalPinToInterrupt(btn_abajo),funcion_ISR_falling,FALLING); //Anclar la interrupcion del pin 10 a una funcion de ISR, disparado por el flanco
}
void loop() {
  if(f_print){
    f_print = false; //Limpio la variable
    if(unidades > 9){
      decenas++;
      unidades = 0;
    }
    if(unidades == -1){
      unidades = 9;
      decenas--;
    }
    if(decenas < 0){
      unidades = 0;
      decenas = 5;
    }
    if(unidades > 0 && decenas == 5){
      unidades = 0;
      decenas = 0;
    }
    
  }
  display_primero();
  display_segundo();
}
//Funciones ISR
void funcion_ISR_rising(void){
  unidades ++; //aunmento el valor de la variable
  f_print = true;
}
void funcion_ISR_falling(void){
  unidades --; //disminuyo el valor de la variable  
  f_print = true;
}
void display_primero(){
  if(unidades==0){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
   if(unidades==1){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
  if(unidades==2){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  }
  if(unidades==3){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  }
  if(unidades==4){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
  if(unidades==5){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
  if(unidades==6){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  }
  if(unidades==7){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  }
  if(unidades==8){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
  if(unidades==9){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
}
void display_segundo(){
  if(decenas==0){
    digitalWrite(A0, LOW);
    digitalWrite(B0, LOW);
    digitalWrite(C0, LOW);
    digitalWrite(D0, LOW);
  }
  if(decenas==1){
  digitalWrite(A0, LOW);
  digitalWrite(B0, LOW);
  digitalWrite(C0, LOW);
  digitalWrite(D0, HIGH);
  }
  if(decenas==2){
  digitalWrite(A0, LOW);
  digitalWrite(B0, LOW);
  digitalWrite(C0, HIGH);
  digitalWrite(D0, LOW);
  } 
  if(decenas==3){
  digitalWrite(A0, LOW);
  digitalWrite(B0, LOW);
  digitalWrite(C0, HIGH);
  digitalWrite(D0, HIGH);
  }  
  if(decenas==4){
  digitalWrite(A0, LOW);
  digitalWrite(B0, HIGH);
  digitalWrite(C0, LOW);
  digitalWrite(D0, LOW);
  }
  if(decenas==5){
  digitalWrite(A0, LOW);
  digitalWrite(B0, HIGH);
  digitalWrite(C0, LOW);
  digitalWrite(D0, HIGH);
  } 
}
