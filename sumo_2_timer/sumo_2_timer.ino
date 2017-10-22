#include <Event.h>
#include <Timer.h>

#define sen_uno_echo 13
#define sen_uno_trig 12
#define sen_dos_echo 3
#define sen_dos_trig 2
#define motor_uno_A 4
#define motor_uno_B 5
#define motor_dos_A 6
#define motor_dos_B 7
#define pwm_uno 10
#define pwm_dos 11
Timer t1;
Timer t2;
long distancia_uno, distancia_dos, tiempo, dist1_prev_1, dist1_prev_2;
bool hayAlgo1, hayAlgo2;
void takeReading1();
void takeReading2();
void modificarMotor1();
void modificarMotor2();

void setup() {
  pinMode(sen_uno_trig, OUTPUT);
  pinMode(sen_uno_echo, INPUT);
  pinMode(sen_dos_trig, OUTPUT);
  pinMode(sen_dos_echo, INPUT);
  pinMode(motor_uno_A, OUTPUT);
  pinMode(motor_uno_B, OUTPUT);
  pinMode(motor_dos_A, OUTPUT);
  pinMode(motor_dos_B, OUTPUT);
  digitalWrite(motor_uno_A, LOW);
  digitalWrite(motor_uno_B, LOW);
  digitalWrite(motor_dos_A, LOW);
  digitalWrite(motor_dos_B, LOW);
  analogWrite(pwm_uno, 0);
  analogWrite(pwm_dos, 0);
  Serial.begin(9600);
  t1.every(70, takeReading1);
  t1.every(70, takeReading2);
  t1.every(100, modificarMotor1);
  t1.every(100, modificarMotor2);
  distancia_uno = 0;
  distancia_dos = 0;
  dist1_prev_1 = -1;
  dist1_prev_2 = -1;
  tiempo = 0;
}

void loop() {
  t1.update();
  Serial.print("Sensor uno --");
  Serial.println(distancia_uno);
  Serial.print("\t \t");
  Serial.print("Sensor dos --");
  Serial.println(distancia_dos);
}
void takeReading1() {
  long dist_tmp, prom;
  digitalWrite(sen_uno_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(sen_uno_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sen_uno_trig, LOW);
  tiempo = pulseIn(sen_uno_echo, HIGH);
  dist_tmp = tiempo / 58;
  if (dist_tmp < 50) {
    hayAlgo1 = true;
  } else {
    hayAlgo1 = false;
  }


}
void takeReading2() {
  long dist_tmp;
  digitalWrite(sen_dos_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(sen_dos_trig, HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(sen_dos_echo, HIGH);
  dist_tmp = tiempo / 58;
  if (dist_tmp < 50) {
    hayAlgo2 = true;
  } else {
    hayAlgo2 = false;
  }
}
void modificarMotor1() {
  if (hayAlgo1) {
    digitalWrite(motor_uno_A, LOW);
    digitalWrite(motor_uno_B, HIGH);
    analogWrite(pwm_uno, 255);
  } else {
    digitalWrite(motor_uno_A, LOW);
    digitalWrite(motor_uno_B, LOW);
    analogWrite(pwm_uno, 0);
  }
}
void modificarMotor2() {
  if (hayAlgo2) {
    digitalWrite(motor_dos_A, LOW);
    digitalWrite(motor_dos_B, HIGH);
    analogWrite(pwm_dos, 255);
  } else {
    digitalWrite(motor_dos_A, LOW);
    digitalWrite(motor_dos_B, LOW);
    analogWrite(pwm_dos, 0);
  }
}
