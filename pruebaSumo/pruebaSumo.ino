#include <motor.h>
#include <sensores.h>
#include <sumo.h>

SumoConfig Sconfig;

Sumo gigabyte;

void setup() {
  Sconfig.pinMotorIzqPos = 10;
  Sconfig.pinMotorIzqNeg = 11;
  Sconfig.pinPwmIzq = 6;
  Sconfig.pinMotorDerPos = 8;
  Sconfig.pinMotorDerNeg = 9;
  Sconfig.pinPwmDer = 6;
  Sconfig.pinIr1 = 0;
  Sconfig.pinIr2 = 0;
  Sconfig.pinUltraTrig1 = 3;
  Sconfig.pinUltraEcho1 = 2;
  Sconfig.pinUltraTrig2 = 12;
  Sconfig.pinUltraEcho2 = 13;
  Sconfig.pinBtnActivar = 0;
  Sconfig.pinBtnModo = 0;

  gigabyte.init(Sconfig);

  Serial.begin(9800);
  
}

void loop() {
  gigabyte.avanzar(150);
  delay(2000);
  gigabyte.retroceder(150);
  delay(2000);
  gigabyte.detener();
  delay(2000);
  gigabyte.girarSobreEje(150,1);
  delay(2000);
  gigabyte.girarSobreEje(150,0);
  delay(2000);
  gigabyte.doblar(150,1);
  delay(2000);
  gigabyte.doblar(150,0);
  Serial.print("sensor 1: ");
  Serial.println(gigabyte.leerUltrasonido(1));
  Serial.print("sensor 2: ");
  Serial.println(gigabyte.leerUltrasonido(2));

}
