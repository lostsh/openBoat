/* Programme de pilotage du bateau
 * 
 * Servomotor
 * Attach D8 (Yellow) GND to GND | 5v to 5v
 * 
 * Motor
 * GND -> Mosquito Pin
 * 5V -> 5V
 * Mosquito Midle -> PIN5
 * Misquito GND -> GND
 * 
 * BLE
 * VCC -> +5V
 * GND -> GND
 * RXD -> D10
 * TXD -> D11
*/

#include <Servo.h>
#include <SoftwareSerial.h>

Servo direction;
SoftwareSerial btSerial(11, 12);//(TX, RX)

const int motorPin = 8;

void setup() {
  direction.attach(4);
  direction.write(90);
  
  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  char incoming = '-';
  zero();
  
  if(Serial.available()){
    incoming = Serial.read();
  }
  if(btSerial.available()){
    incoming = btSerial.read();
  }
  
  switch(incoming){
    case 'f':
      run();
      Serial.println("Run");
      break;
    case 's':
      stop();
      Serial.println("Stop");
      break;
    case 'r':
      right();
      Serial.println("Turn Right");
      break;
    case 'l':
      left();
      Serial.println("Turn Left");
      break;/*
    default:
      Serial.println("Unknow argument\nf -> run forward\ns -> stop\nr -> turn right\nl -> turn left");
      break;*/
  }
  
  delay(250);
}
