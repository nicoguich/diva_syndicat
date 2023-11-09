// Bounce.pde
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//
// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $
#include <Conceptinetics.h>
#include <AccelStepper.h>
int chiffre=0, chiffre_temp=0;
// Define a stepper and the pins it will use
AccelStepper stepper(1, 3, 4); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
int incomingByte;


#define DMX_SLAVE_CHANNELS   2 
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

void setup()
{  
  //Serial.begin(9600);
  // Change these to suit your stepper if you want

  pinMode(8,INPUT);
  stepper.setMaxSpeed(1600);
  stepper.setAcceleration(400);


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
    chiffre=int(incomingByte)-48;
    if (chiffre>chiffre_temp){
      stepper.moveTo((chiffre-chiffre_temp)*-80);
    }
    else{
stepper.moveTo(((10-chiffre_temp)*-80)+((chiffre)*-80));

    }
    }
  }
*/

if ((dmx_slave.getChannelValue (1)/2.55)<100){

chiffre= round(dmx_slave.getChannelValue (1)/2.55);
    if (chiffre>chiffre_temp){
      stepper.moveTo((chiffre-chiffre_temp)*-80);
    }
    else if( chiffre<chiffre_temp){
stepper.moveTo(((10-chiffre_temp)*-80)+((chiffre)*-80));

    }
}
  
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0){
      stepper.setCurrentPosition(0);
      chiffre_temp=chiffre;
  //    Serial.print("chiffre:");
 //     Serial.print(chiffre);
   //   Serial.print("    chiffretemp:");
   //   Serial.println(chiffre_temp);
     
     }

if(digitalRead(8)==0){
  chiffre_temp=0;
}
    stepper.run();
}
