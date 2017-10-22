#include <motor.h>
#include <sensores.h>

Ultrasonido ultra1;
Ultrasonido ultra2;

void setup() {
  Serial.begin(9800);
  ultra1.init(3,2);
  ultra2.init(12,13);
}

void loop() {
 long dif, dist1, dist2;
  dist1 =ultra1.retornarDistancia();
  delayMicroseconds(50);
  dist2 = ultra2.retornarDistancia();
  dif = dist1 - dist2;

  Serial.print(dist1);
  Serial.print(" ");
  Serial.print(dist2);
  Serial.print(" ");
  Serial.print(dif);
  Serial.print(" ");
  Serial.println("");
  delay(300);
}
