#include <motor.h>
#include <sensores.h>

Motor motorDer;
Motor motorIzq;

void setup() {
  motorDer.init(8,9,5);
  motorIzq.init(10,11,6);
}

void loop() {
  
    motorDer.avanzar(150);
    delay(2000);
    motorDer.retroceder(150);
    delay(2000);
    motorDer.avanzar(255);
    delay(2000);
    motorDer.retroceder(255);
    delay(2000);
    motorDer.detener();
       
    motorIzq.avanzar(150);
    delay(2000);
    motorIzq.retroceder(150);
    delay(2000);
    motorIzq.avanzar(255);
    delay(2000);
    motorIzq.retroceder(255);
    delay(2000);
    motorIzq.detener();
}
