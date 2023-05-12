/*Pontificia Universidad 
 Indicador sonoro de objetos
    Daniel Andrés Pineda Suárez*/
#include "Ultrasonic.h"     //Se incluye la librería del arduino para el HCSR04
Ultrasonic ultrasonic(7,6); //Se establece las variables: Impulso, recepción respectivamente

// Señal acustica
#include "pitches.h"        //Se incluye las librerías que contiene cada tono
int timbre;                  //variable 
int nota = NOTE_E5;       //Existen distintas notas para la librería de arduino, en mi caso elegí la E6 Tono o nota elegida para que suene

void setup()
{
  Serial.begin(9600);    //Establece la comunicación con el puerto serial
}

void loop()
{
   
   timbre = ultrasonic.Ranging(CM); 
if (timbre > 15)             //Mientras que la distancia sea mayor a 15 cm la frecuencia del tono se intencifica

   {       
       delay(timbre);                 
       noTone(7);                  //Detiene la generación de ondas cuadradas por impulsos
       tone(8,timbre);             //Aviso 
       delay(250);                 //Duración del timbre
       noTone(8);                  //Apagamos el sonido
    
       }  
       timbre = ultrasonic.Ranging(CM); // se verifica la distancia para repetir el bucle
    
    }
   