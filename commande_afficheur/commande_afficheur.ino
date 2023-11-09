// Bounce.pde
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//
// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $
#include <Conceptinetics.h>
#include <AccelStepper.h>
int unite=0, unite_temp=0;
int deci=0, deci_temp=0;
// Define a stepper and the pins it will use
AccelStepper stepper_unite(1, 3, 4); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper_deci(1, 5, 6);
int incomingByte;

int unite_sensor_pin=8;
int deci_sensor_pin=7;


#define DMX_SLAVE_CHANNELS   2 
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

void setup()
{  
  //Serial.begin(9600);
  // Change these to suit your stepper if you want

  pinMode(unite_sensor_pin,INPUT);
  stepper_unite.setMaxSpeed(1600);
  stepper_unite.setAcceleration(400);
  stepper_deci.setMaxSpeed(1600);
  stepper_deci.setAcceleration(400);


  dmx_slave.enable (); 
  dmx_slave.setStartAddress (1);
}

void loop()
{
/*
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if (incomingByte-48>=0){
    //Serial.println(int(incomingByte)-48);
    unite=int(incomingByte)-48;
    if (unite>unite_temp){
      stepper.moveTo((unite-unite_temp)*-80);
    }
    else{
stepper.moveTo(((10-unite_temp)*-80)+((unite)*-80));

    }
    }
  }
*/

if (round(dmx_slave.getChannelValue (1)/2.55)<100){

unite = (round(dmx_slave.getChannelValue (1)/2.55) );
unite= unite % 10;
    if (unite>unite_temp){
      stepper_unite.moveTo((unite-unite_temp)*-80);
    }
    else if( unite<unite_temp){
stepper_unite.moveTo(((10-unite_temp)*-80)+((unite)*-80));

    }

deci = (round(dmx_slave.getChannelValue (1)/2.55) );
deci= int((deci % 100)/10);
    if (deci>deci_temp){
      stepper_deci.moveTo((deci-deci_temp)*-80);
    }
    else if( deci<deci_temp){
stepper_deci.moveTo(((10-deci_temp)*-80)+((deci)*-80));

    }

}
  
    // If at the end of travel go to the other end
    if (stepper_unite.distanceToGo() == 0){
      stepper_unite.setCurrentPosition(0);
      unite_temp=unite;
  //    Serial.print("unite:");
 //     Serial.print(unite);
   //   Serial.print("    unitetemp:");
   //   Serial.println(unite_temp);
     
     }


         // If at the end of travel go to the other end
    if (stepper_deci.distanceToGo() == 0){
      stepper_deci.setCurrentPosition(0);
      deci_temp=deci;
  //    Serial.print("unite:");
 //     Serial.print(unite);
   //   Serial.print("    unitetemp:");
   //   Serial.println(unite_temp);
     
     }

if(digitalRead(unite_sensor_pin)==0){
  unite_temp=0;
}
    stepper_unite.run();
    stepper_deci.run();
}
