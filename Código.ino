#include <Servo.h>  // Incluye la librería Servo

Servo servos[13];  // Crea un array de 13 objetos Servo

int derecho = 9;   // Pin del servo derecho
int izquierdo = 8; // Pin del servo izquierdo
int blanco = 0;    // Valor de un sensor de línea que detecta blanco
int negro = 1;     // Valor de un sensor de línea que detecta negro

void setup()
{
  pinMode(3, INPUT);  // Configura el pin 3 como entrada
  pinMode(2, INPUT);  // Configura el pin 2 como entrada
}

void loop()
{
  int ir_derecho = digitalRead(3);   // Lee el valor del sensor derecho
  int ir_izquierdo = digitalRead(2); // Lee el valor del sensor izquierdo

  // Si no detecta la línea a la derecha, gira hacia la derecha
  if (ir_derecho == 1 && ir_izquierdo == 0) {
    paDerecha();
  }
  // Si no detecta la línea a la izquierda, gira hacia la izquierda
  else if (ir_derecho == 0 && ir_izquierdo == 1) {
    paIzquierda();
  }
  // Si detecta la línea en ambos sensores, avanza
  else if (ir_derecho == 0 && ir_izquierdo == 0) {
    paDelante();
  }
  // Si no detecta la línea, gira hacia la derecha
  else {
    paDerecha();
  }
}

// Función que hace girar el robot hacia la derecha
void paDerecha() {
  servos[izquierdo].attach(izquierdo); // Conecta el servo izquierdo al pin correspondiente
  servos[izquierdo].write(-180);       // Gira el servo izquierdo hacia atrás

  servos[derecho].attach(derecho);     // Conecta el servo derecho al pin correspondiente
  servos[derecho].write(-180);         // Gira el servo derecho hacia atrás
}

// Función que hace girar el robot hacia la izquierda
void paIzquierda() {
  servos[izquierdo].attach(izquierdo); // Conecta el servo izquierdo al pin correspondiente
  servos[izquierdo].write(180);        // Gira el servo izquierdo hacia adelante

  servos[derecho].attach(derecho);     // Conecta el servo derecho al pin correspondiente
  servos[derecho].write(180);          // Gira el servo derecho hacia adelante
}

// Función que hace avanzar el robot
void paDelante() {
  servos[izquierdo].attach(izquierdo); // Conecta el servo izquierdo al pin correspondiente
  servos[izquierdo].write(-180);       // Gira el servo izquierdo hacia atrás

  servos[derecho].attach(derecho);     // Conecta el servo derecho al pin correspondiente
  servos[derecho].write(180);          // Gira el servo derecho hacia adelante
}
