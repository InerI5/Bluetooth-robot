#pragma once

#include <Arduino.h>

class Drive
{
  public:
  void SetLeftUpMotor(char motor_port1,char motor_port2)
  {
    d1_1_port=motor_port1;
    pinMode(motor_port1,OUTPUT);
    d1_2_port=motor_port2;
    pinMode(motor_port2,OUTPUT);
  }
  void SetRiteUpMotor(char motor_port1,char motor_port2)
  {
    d2_1_port=motor_port1;
    pinMode(motor_port1,OUTPUT);
    d2_2_port=motor_port2;
    pinMode(motor_port2,OUTPUT);
  }
  void SetLeftDownMotor(char motor_port1,char motor_port2)
  {
    d3_1_port=motor_port1;
    pinMode(motor_port1,OUTPUT);
    d3_2_port=motor_port2;
    pinMode(motor_port2,OUTPUT);
  }
  void SetRiteDownMotor(char motor_port1,char motor_port2)
  {
    d4_1_port=motor_port1;
    pinMode(motor_port1,OUTPUT);
    d4_2_port=motor_port2;
    pinMode(motor_port2,OUTPUT);
  }
  void SetAll(char m_p1_1,char m_p1_2,char m_p2_1,char m_p2_2,char m_p3_1,char m_p3_2,char m_p4_1,char m_p4_2)
  {
    d1_1_port=m_p1_1;
    d2_1_port=m_p2_1;
    d3_1_port=m_p3_1;
    d4_1_port=m_p4_1;
    d1_2_port=m_p1_2;
    d2_2_port=m_p2_2;
    d3_2_port=m_p3_2;
    d4_2_port=m_p4_2;
    pinMode(m_p1_1,OUTPUT);
    pinMode(m_p2_1,OUTPUT);
    pinMode(m_p3_1,OUTPUT);
    pinMode(m_p4_1,OUTPUT);
    pinMode(m_p1_2,OUTPUT);
    pinMode(m_p2_2,OUTPUT);
    pinMode(m_p3_2,OUTPUT);
    pinMode(m_p4_2,OUTPUT);
  }
  void RideRiteUpMotor(int torpue,bool directionn=true)
   {
    if(directionn){
    analogWrite(d1_1_port,torpue);
    analogWrite(d1_2_port,0);
    }else{
      analogWrite(d1_2_port,torpue);
      analogWrite(d1_1_port,0);
    }
   }
    void RideLeftUpMotor(int torpue,bool directionn=true)
   {
    if(directionn){
    analogWrite(d2_1_port,torpue);
    analogWrite(d2_2_port,0);
    }else{
      analogWrite(d2_2_port,torpue);
      analogWrite(d2_1_port,0);
    }
   }
    void RideRiteDownMotor(int torpue,bool directionn=true)
   {
    if(directionn){
    analogWrite(d3_1_port,torpue);
    analogWrite(d3_2_port,0);
    }else{
      analogWrite(d3_2_port,torpue);
      analogWrite(d3_1_port,0);
    }
   }
    void RideLeftDownMotor(int torpue,bool directionn=true)
   {
    if(directionn){
    analogWrite(d4_1_port,torpue);
    analogWrite(d4_2_port,0);
    }else{
      analogWrite(d4_2_port,torpue);
      analogWrite(d4_1_port,0);
    }
   }
   void RideLeftMotors(int torpue,bool directionn=true)
   { 
    RideLeftDownMotor(torpue,directionn);
    RideLeftUpMotor(torpue,directionn);
   }
   
   void RideRightMotors(int torpue,bool directionn=true)
   {
    RideRiteDownMotor(torpue,directionn);
    RideRiteUpMotor(torpue,directionn);
   }

    void RideUpMotors(int torpue,bool directionn=true)
   { 
    RideRiteUpMotor(torpue,directionn);
    RideLeftUpMotor(torpue,directionn);
   }

   void RideDownMotors(int torpue,bool directionn=true)
   { 
    RideRiteDownMotor(torpue,directionn);
    RideLeftDownMotor(torpue,directionn);
   }
   
  
  private:
  char d1_1_port; //вперёд
  char d1_2_port; //назад
  char d2_1_port; //вперёд
  char d2_2_port; //назад
  char d3_1_port; //вперёд
  char d3_2_port; //назад
  char d4_1_port; //вперёд
  char d4_2_port; //назад
};
