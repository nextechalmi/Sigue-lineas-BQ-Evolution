# Sigue-líneas en BQ Evolution
## Descripción general

Este código se usa para controlar un robot BQ Evolution que sigue líneas. El robot tiene dos sensores de línea que detectan si el suelo debajo de ellos es blanco o negro. Dependiendo de la lectura de los sensores, el robot gira hacia la derecha, hacia la izquierda o avanza recto para seguir la línea.
Incluyendo la librería Servo

```c

#include <Servo.h>  // Incluye la librería Servo
```

Esta línea de código incluye la librería Servo necesaria para controlar los servomotores del robot.
Creando un array de objetos Servo

```c

Servo servos[13];  // Crea un array de 13 objetos Servo
```
Este código crea un array de 13 objetos Servo que se utilizarán para controlar los servomotores del robot.
Definiendo los pines de los servomotores y los sensores

```c

int derecho = 9;   // Pin del servo derecho
int izquierdo = 8; // Pin del servo izquierdo
int blanco = 0;    // Valor de un sensor de línea que detecta blanco
int negro = 1;     // Valor de un sensor de línea que detecta negro
```

Estas líneas de código definen los pines a los que están conectados los servomotores y los valores que se obtienen cuando los sensores detectan blanco o negro.

## Configurando los pines de entrada

```c

void setup()
{
  pinMode(3, INPUT);  // Configura el pin 3 como entrada
  pinMode(2, INPUT);  // Configura el pin 2 como entrada
}
```
En el método setup(), se configuran los pines 3 y 2 como pines de entrada para los sensores derecho e izquierdo, respectivamente.
Controlando los servomotores en el método loop()

```c

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
```

El método loop() se encarga de controlar los servomotores dependiendo de las lecturas de los sensores. Si el sensor derecho detecta negro y el izquierdo detecta blanco, el robot gira a la derecha llamando a la función paDerecha().

La función paIzquierda() es llamada cuando el sensor derecho detecta una línea blanca y el sensor izquierdo detecta una línea negra. Su objetivo es hacer girar al robot hacia la izquierda.

```C

void paIzquierda() {
  servos[izquierdo].attach(izquierdo); // Conecta el servo izquierdo al pin correspondiente
  servos[izquierdo].write(180);        // Gira el servo izquierdo hacia adelante

  servos[derecho].attach(derecho);     // Conecta el servo derecho al pin correspondiente
  servos[derecho].write(180);          // Gira el servo derecho hacia adelante
}

    servos[izquierdo].attach(izquierdo);: conecta el servo izquierdo al pin izquierdo para que pueda recibir señales.
    servos[izquierdo].write(180);: hace que el servo izquierdo gire hacia adelante, en dirección a la izquierda, moviendo las ruedas del robot en esa dirección.
    servos[derecho].attach(derecho);: conecta el servo derecho al pin derecho para que pueda recibir señales.
    servos[derecho].write(180);: hace que el servo derecho gire hacia adelante, en dirección a la izquierda, moviendo las ruedas del robot en esa dirección.
```

## Función paDelante()

La función paDelante() es llamada cuando los sensores no detectan ninguna línea. Su objetivo es hacer avanzar al robot hacia adelante.

```C

void paDelante() {
  servos[izquierdo].attach(izquierdo); // Conecta el servo izquierdo al pin correspondiente
  servos[izquierdo].write(-180);       // Gira el servo izquierdo hacia atrás

  servos[derecho].attach(derecho);     // Conecta el servo derecho al pin correspondiente
  servos[derecho].write(180);          // Gira el servo derecho hacia adelante
}

    servos[izquierdo].attach(izquierdo);: conecta el servo izquierdo al pin izquierdo para que pueda recibir señales.
    servos[izquierdo].write(-180);: hace que el servo izquierdo gire hacia atrás, moviendo las ruedas del robot hacia adelante.
    servos[derecho].attach(derecho);: conecta el servo derecho al pin derecho para que pueda recibir señales.
    servos[derecho].write(180);: hace que el servo derecho gire hacia adelante, moviendo las ruedas del robot hacia adelante.
```
Con esto hemos analizado todas las funciones y su propósito en el código del robot que sigue líneas.
