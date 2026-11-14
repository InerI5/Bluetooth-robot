 #pragma once

#include <Arduino.h>
 class Dalnomer
{
 public:
 void Ports(int trig ,int echo )
 {
   trigPin=trig;
   echoPin=echo;
    pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

 }

int Poluch_Dan() 
 { 
  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH, 10000); 
    cm = duration / 58;
Serial.println(cm);

    return cm;
 }
 

 private:
 int duration, cm; 
 int trigPin ;
 int echoPin ;
};
 