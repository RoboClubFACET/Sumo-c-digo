#include <motor.h>
#include <sensores.h>
#include <sumo.h>
#include <Event.h>
#include <Timer.h>

#define btn 7
bool interuptBool = 0;

SumoConfig Sconfig;

Sumo gigabyte;


long distancia1, distancia2, diferencia, valorChico, valorBasura, dire = 0;

void leerSensores();

void moverGigabyte();

Timer t1;

void setup() {
  bool pressed = 0;
  
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

  t1.every(70, leerSensores);
  t1.every(100, moverGigabyte);

  Serial.begin(9800);

  while (!pressed)
  {
    pressed = digitalRead(btn);
  }
  delay(5000);

}

void loop() {
  t1.update();

}

void leerSensores()
{
  distancia1 = gigabyte.leerUltrasonido(1);
  if (distancia1 > 100)
  {
    distancia1 = 800;
  }
  distancia2 = gigabyte.leerUltrasonido(2);
  if (distancia2 > 100)
  {
    distancia2 = 800;
  }
  
  diferencia = distancia1 - distancia2;
}
void moverGigabyte()
{
  if (distancia1 == 800 && distancia2 == 800)
  {
    dire = random(2);
    Serial.println(dire);
    gigabyte.girarSobreEje(255, dire);
    delay(600);'
  }
  else if (abs(diferencia) < 15)
  {
    gigabyte.avanzar(255);
  } 
  else if (diferencia < 0) 
  {
    gigabyte.girarSobreEje(255, 1);
  }
  else
  {
    gigabyte.girarSobreEje(255, 0);
  }
  
  delay(50);
}
