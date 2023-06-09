/*
Pontificia Universidad Javeriana
Daniel Andr�s Pineda Su�rez- 
Proyecto Primer semestre_senales
    AKA3000 
*/
int Trig= 38;// Variable que los define pines del sensor de ultra sonido
int Echo= 36; // Variable que define los pines del sensor de ultra sonido
#include <AFMotor.h> // La siguiente librer�a describe el movimiento y control de los motores mediante 

AF_DCMotor right(1,MOTOR12_64KHZ); // Frecuencia de PWM (para controlar la velocidad de giro del motor)  64kHz primer motor(recomendado por el m�dulo de Adafruiten su respectiva datasheet)

AF_DCMotor left(2,MOTOR12_64KHZ); // Hz segundo motor

void setup() {
  
Serial.begin(9600); //La mayor�a de ordenadores emplean la variable como 9600, que es lo recomendado por Arduino

pinMode(Trig, OUTPUT); // Se define el Trig como pin de impulso o salida
pinMode(Echo, INPUT); // Se define el Echo como pin de recepci�n o entrada

right.setSpeed(250); // velocidad de ambos motores
left.setSpeed (250);  

}
 
void loop() { //creo la funci�n loop para la realizaci�n de un bucle



digitalWrite(Trig, LOW); // Trigger apagado  
delayMicroseconds(2); //Se utiliz� la librer�a de arduino de delay
  
digitalWrite(Trig, HIGH); // Se enciende trigger 
delayMicroseconds(15); // Se env�a un 1 durante 15 microsegundos
digitalWrite(Trig, LOW); // se define trigger como bajo
long tiempo, espacio; // Se crean 2 variables, para almacenar con tiempo en ms y espacio en cm
tiempo = pulseIn(Echo, HIGH); // Calcular la duracion del Pulso  
espacio = (tiempo/2) / 29.1; // distancia a tiempo como sale en data sheet Test distance = (high level time�velocity of sound (340M/S) / 2,
 Serial.println(espacio); 

if (espacio < 20 ) {  // Si la distancia es menor a 20cm girar a la izquierda   right.run(FORWARD);  // Avanza el motor de la derecha (donde BACKWARD es atr�s, FORWARD es adelante)

{
left.run (BACKWARD);
delay (150);
right.run(BACKWARD);
delay (150);

}

left.run (BACKWARD); // Se cambia la polaridad del motor de la izquierda
delay (150); // Se pone el tiempo de giro
right. run(RELEASE);// Se detiene el motor
delay (0);

}

else {
   
delay (20); // Estabilizar los motores mediante un retraso o pausa de 20 milisegundos
right.run(FORWARD); //siga avanzando   
left.run(FORWARD);  
}  

}
