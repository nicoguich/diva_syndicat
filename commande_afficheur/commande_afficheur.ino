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
AccelStepper stepper_unite(1, 17, 16); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper_deci(1, 15, 14);
int incomingByte;

int unite_sensor_pin=41;
int deci_sensor_pin=29;
int demarrage_unite=0;
int demarrage_deci=0;
int offset_sensor=-150;
int relay_pin=47;

int dmx_unite=0;
int dmx_dizaine=0;
int dmx_centaine=0;
int dmx_adresse=1;


#define DMX_SLAVE_CHANNELS   2 
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

void setup()
{  
  //Serial.begin(9600);
 

  pinMode(unite_sensor_pin,INPUT);
  pinMode(deci_sensor_pin,INPUT);
  pinMode( relay_pin,OUTPUT);

pinMode(21,INPUT_PULLUP);
pinMode(20,INPUT_PULLUP);
pinMode(19,INPUT_PULLUP);
pinMode(18,INPUT_PULLUP);

pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);

pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);


  
 // digitalWrite(relay_pin,LOW);

  stepper_unite.setMaxSpeed(800);
  stepper_unite.setAcceleration(800);
  stepper_deci.setMaxSpeed(800);

  stepper_deci.setAcceleration(800);


  if ((digitalRead(21)==1)&&(digitalRead(20)==1)&&(digitalRead(19)==1)&&(digitalRead(18)==1)){
  dmx_unite=0;
}
if ((digitalRead(21)==0)&&(digitalRead(20)==1)&&(digitalRead(19)==1)&&(digitalRead(18)==1)){
  dmx_unite=1;
}
if ((digitalRead(21)==1)&&(digitalRead(20)==1)&&(digitalRead(19)==1)&&(digitalRead(18)==0)){
  dmx_unite=2;
}
if ((digitalRead(21)==0)&&(digitalRead(20)==1)&&(digitalRead(19)==1)&&(digitalRead(18)==0)){
  dmx_unite=3;
}
if ((digitalRead(21)==1)&&(digitalRead(20)==0)&&(digitalRead(19)==1)&&(digitalRead(18)==1)){
  dmx_unite=4;
}
if ((digitalRead(21)==0)&&(digitalRead(20)==0)&&(digitalRead(19)==1)&&(digitalRead(18)==1)){
  dmx_unite=5;
}
if ((digitalRead(21)==1)&&(digitalRead(20)==0)&&(digitalRead(19)==1)&&(digitalRead(18)==0)){
  dmx_unite=6;
}
if ((digitalRead(21)==0)&&(digitalRead(20)==0)&&(digitalRead(19)==1)&&(digitalRead(18)==0)){
  dmx_unite=7;
}
if ((digitalRead(21)==1)&&(digitalRead(20)==1)&&(digitalRead(19)==0)&&(digitalRead(18)==1)){
  dmx_unite=8;
}
if ((digitalRead(21)==0)&&(digitalRead(20)==1)&&(digitalRead(19)==0)&&(digitalRead(18)==1)){
  dmx_unite=9;
}

if ((digitalRead(9)==1)&&(digitalRead(8)==1)&&(digitalRead(7)==1)&&(digitalRead(6)==1)){
  dmx_dizaine=0;
}
if ((digitalRead(9)==1)&&(digitalRead(8)==0)&&(digitalRead(7)==1)&&(digitalRead(6)==1)){
  dmx_dizaine=1;
}if ((digitalRead(9)==1)&&(digitalRead(8)==1)&&(digitalRead(7)==0)&&(digitalRead(6)==1)){
  dmx_dizaine=2;
}if ((digitalRead(9)==1)&&(digitalRead(8)==0)&&(digitalRead(7)==0)&&(digitalRead(6)==1)){
  dmx_dizaine=3;
}if ((digitalRead(9)==0)&&(digitalRead(8)==1)&&(digitalRead(7)==1)&&(digitalRead(6)==1)){
  dmx_dizaine=4;
}if ((digitalRead(9)==0)&&(digitalRead(8)==0)&&(digitalRead(7)==1)&&(digitalRead(6)==1)){
  dmx_dizaine=5;
}if ((digitalRead(9)==0)&&(digitalRead(8)==1)&&(digitalRead(7)==0)&&(digitalRead(6)==1)){
  dmx_dizaine=6;
}if ((digitalRead(9)==0)&&(digitalRead(8)==0)&&(digitalRead(7)==0)&&(digitalRead(6)==1)){
  dmx_dizaine=7;
}if ((digitalRead(9)==1)&&(digitalRead(8)==1)&&(digitalRead(7)==1)&&(digitalRead(6)==0)){
  dmx_dizaine=8;
}if ((digitalRead(9)==1)&&(digitalRead(8)==0)&&(digitalRead(7)==1)&&(digitalRead(6)==0)){
  dmx_dizaine=9;
}


if ((digitalRead(5)==1)&&(digitalRead(4)==1)&&(digitalRead(3)==1)&&(digitalRead(2)==1)){
  dmx_centaine=0;
}
if ((digitalRead(5)==1)&&(digitalRead(4)==0)&&(digitalRead(3)==1)&&(digitalRead(2)==1)){
  dmx_centaine=1;
}
if ((digitalRead(5)==1)&&(digitalRead(4)==1)&&(digitalRead(3)==0)&&(digitalRead(2)==1)){
  dmx_centaine=2;
}
if ((digitalRead(5)==1)&&(digitalRead(4)==0)&&(digitalRead(3)==0)&&(digitalRead(2)==1)){
  dmx_centaine=3;
}
if ((digitalRead(5)==0)&&(digitalRead(4)==1)&&(digitalRead(3)==1)&&(digitalRead(2)==1)){
  dmx_centaine=4;
}
if ((digitalRead(5)==0)&&(digitalRead(4)==0)&&(digitalRead(3)==1)&&(digitalRead(2)==1)){
  dmx_centaine=5;
}
if ((digitalRead(5)==0)&&(digitalRead(4)==1)&&(digitalRead(3)==0)&&(digitalRead(2)==1)){
  dmx_centaine=6;
}
if ((digitalRead(5)==0)&&(digitalRead(4)==0)&&(digitalRead(3)==0)&&(digitalRead(2)==1)){
  dmx_centaine=7;
}
if ((digitalRead(5)==1)&&(digitalRead(4)==1)&&(digitalRead(3)==1)&&(digitalRead(2)==0)){
  dmx_centaine=8;
}
if ((digitalRead(5)==1)&&(digitalRead(4)==0)&&(digitalRead(3)==1)&&(digitalRead(2)==0)){
  dmx_centaine=9;
}

dmx_adresse=(dmx_centaine*100)+(dmx_dizaine*10)+dmx_unite;

dmx_slave.setStartAddress (dmx_adresse);
  

 delay(5000);

digitalWrite(relay_pin,HIGH);
}

void loop()
{





if (dmx_slave.getChannelValue (2)<127){

if (demarrage_unite==0){
  stepper_unite.moveTo(-10000);
if(digitalRead(unite_sensor_pin)==1){
  stepper_unite.run();
}
else{
demarrage_unite=1;
unite_temp=0;
stepper_unite.setCurrentPosition(0);
stepper_unite.moveTo(offset_sensor);
 dmx_slave.enable ();}
  
}

if (demarrage_deci==0){
  stepper_deci.moveTo(10000);
if(digitalRead(deci_sensor_pin)==1){
  stepper_deci.run();
}
else{
demarrage_deci=1;
deci_temp=0;
stepper_deci.setCurrentPosition(0);
stepper_deci.moveTo(-offset_sensor);
 dmx_slave.enable ();}
  
}


if ((demarrage_unite!=0)&&(demarrage_deci!=0)) {
if ((demarrage_unite==2)){
if (round(dmx_slave.getChannelValue (1)/2.55)<100){

unite = (round(dmx_slave.getChannelValue (1)/2.55) );
unite= unite % 10;
    if (unite>unite_temp){
      stepper_unite.moveTo((unite-unite_temp)*-160);
    }
    else if( unite<unite_temp){
stepper_unite.moveTo(((10-unite_temp)*-160)+((unite)*-160));

    }


}
}

if (demarrage_deci==2){
if (round(dmx_slave.getChannelValue (1)/2.55)<100){



deci = (round(dmx_slave.getChannelValue (1)/2.55) );
deci= int((deci % 100)/10);
    if (deci>deci_temp){
      stepper_deci.moveTo((deci-deci_temp)*160);
    }
    else if( deci<deci_temp){
stepper_deci.moveTo(((10-deci_temp)*160)+((deci)*160));

    }

}

  
}


    if (stepper_unite.distanceToGo() == 0){
      stepper_unite.setCurrentPosition(0);
      unite_temp=unite;
      if(demarrage_unite==1){
        demarrage_unite=2;
       unite_temp=0;
      }
     
     }



    if (stepper_deci.distanceToGo() == 0){
      stepper_deci.setCurrentPosition(0);
      deci_temp=deci; 
      if(demarrage_deci==1){
        demarrage_deci=2;
       deci_temp=0;
      }
      
}


}
}








else{
  
stepper_deci.moveTo(100000);
  demarrage_deci=0;


stepper_unite.moveTo(-100000);
  demarrage_unite=0;
}


    stepper_unite.run();
    stepper_deci.run();   
}
