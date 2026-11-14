
#include <Arduino.h>
#include "DriveClass.h"
#include "Blutooth.h"
#include "Dalnomers.h"
 Drive motors;
 Bluetooth BT;
 Dalnomer Dat_peredniy;
 Dalnomer Dat_zadniy;
 Dalnomer Dat_leviy;
 Dalnomer Dat_praviy;
 
void setup() {
  motors.SetAll(12,14,27,26,25,33,32,35);
  BT.begin();
  Serial.begin(115200);
  /*Dat_peredniy.Ports(0,2);
  Dat_zadniy.Ports(13,12);
  Dat_leviy.Ports(33,32);
  Dat_praviy.Ports(14,26);
  */
   }

  unsigned long time_no_signal=40000;
  unsigned long before_count=0;

void loop()
{ 
  BT.Priem();
 int gradus=BT.GetGradus();
 int mochnost=BT.GetMochnost();

   if(!ESP_BT.available())
   {
    if (before_count==0)
    {
      before_count=millis();
    }
    if(time_no_signal<=(millis()-before_count))
    {
    motors.RideRightMotors(0);
    motors.RideLeftMotors(0);
    }

   }
   else
   {
    before_count=0;
   }
 
  

  /*if(Dat_peredniy.Poluch_Dan()<20&&gradus<90&&gradus>=0)
  {
 motors.RideRightMotors(0);
 motors.RideLeftMotors(0);
  }
  if(Dat_leviy.Poluch_Dan()<20&&gradus<180&&gradus>90)
  {
 motors.RideRightMotors(0);
 motors.RideLeftMotors(0);
  }
  if(Dat_praviy.Poluch_Dan()<20&&gradus<360&&gradus>270)
  {
 motors.RideRightMotors(0);
 motors.RideLeftMotors(0);
  }
  if(Dat_zadniy.Poluch_Dan()<20&&gradus<270&&gradus>180)
  {
 motors.RideRightMotors(0);
 motors.RideLeftMotors(0);
  }
*/
 if(mochnost<1)
  {
 motors.RideRightMotors(0);
 motors.RideLeftMotors(0);
  }

  if (gradus<90&&gradus>0)
  {
 motors.RideRightMotors(mochnost);
 motors.RideLeftMotors(mochnost*(static_cast<double>(gradus)/90));
 delay(100);
  }
  
  if(gradus<180&&gradus>90)
 {
  motors.RideRightMotors(mochnost*(1-static_cast<double>(gradus-90)/90));
  //Serial.print("moshnost"); Serial.println((mochnost*(1-static_cast<double>(gradus-90)/90)));
  motors.RideLeftMotors(mochnost);
  delay(100);
  }

  if(gradus<270&&gradus>180)
 {
  motors.RideRightMotors(mochnost*(static_cast<double>(gradus-180)/90),false);
  motors.RideLeftMotors(mochnost,false);
  delay(100);
  }

  if(gradus<360&&gradus>270)
 {
  motors.RideRightMotors(mochnost,false);
  motors.RideLeftMotors(mochnost*(1-static_cast<double>(gradus-270)/90),false);
  delay(100);
  }
}
  
    
