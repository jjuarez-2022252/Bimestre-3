

//Librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Directivas de Preprocesado
#define boton 2

void sensortemp();
void botonn();

//Constructores
Ticker accion_temperatura(sensortemp,3000);
Ticker state_boton(botonn,6000);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  accion_temperatura.start();
  state_boton.start();
  sensor.begin();
}

void loop() {
  accion_temperatura.update();
  state_boton.update();
}

void sensortemp(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.println("Sensor de Temperatura");
  Serial.print("La Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}

void botonn(){
  int estado = digitalRead(boton);
 
  if(estado == HIGH){
    Serial.println("El boton se encuentra");
    Serial.println("Presionado");
  }

  if(estado == LOW){
    Serial.println("El boton se encuentra");
    Serial.println(" No Presionado");
  }
}
