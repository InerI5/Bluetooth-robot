#pragma once

#define DEBUG 

#include <Arduino.h>
#include <functional>
#include "BluetoothSerial.h"

  BluetoothSerial ESP_BT; // Объект для Bluetooth 
 class Bluetooth
 {
   public:
void begin()
{
  ESP_BT.begin("ESP32_CAR_Control2"); // Задаем имя вашего устройства Bluetooth
  #ifdef DEBUG 
    Serial.println("Bluetooth Device is Ready to Pair");  // По готовности сообщаем, что устройство готово к сопряжению
  #endif
}

void Priem() {
if (ESP_BT.available()) // Проверяем, не получили ли мы что-либо от Bluetooth модуля
  {        
    while(nomber<8){
      if (ESP_BT.available()){
        incoming[nomber++] = ESP_BT.read(); // Читаем, что получили

        #ifdef DEBUG
          Serial.print("Received:"); Serial.println(incoming[nomber-1]);   
        #endif
      }
    }
      gradus=0;
      mochnost=0;
      nomber=0;
      gradus+= (incoming[0]-'0')*100;
      gradus+= (incoming[1]-'0')*10;
      gradus+= (incoming[2]-'0');
      mochnost+= (incoming[3]-'0')*1000;
      mochnost+= (incoming[4]-'0')*100;
      mochnost+= (incoming[5]-'0')*10;
      mochnost+= (incoming[6]-'0');
    #ifdef DEBUG 
      Serial.println(gradus);Serial.println(mochnost);
    #endif
    
      while(ESP_BT.available()){
      ESP_BT.read();
      }
}else{
   gradus=0;
      mochnost=0;
      nomber=0;
}
}

  int GetGradus(){
    return gradus;
  }
  
  int GetMochnost(){
    return mochnost;
  }
  
  
 private:
unsigned int gradus=0;
unsigned int mochnost=0;
char incoming[10]={};
int8_t nomber=0; 
};
