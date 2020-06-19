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
  //zero();
  
  if(Serial.available()){
    incoming = Serial.read();
  }
  if(btSerial.available()){
    incoming = btSerial.read();
  }
  
  switch(incoming){
    case 'F':
      run();
      Serial.println("Run");
      break;
    case 'S':
      stop();
      Serial.println("Stop");
      break;
    case 's':
      stop();
      Serial.println("Stop");
      break;
    case 'R':
      right();
      Serial.println("Turn Right");
      break;
    case 'L':
      left();
      Serial.println("Turn Left");
      break;
    case 'Z':
      zero();
      Serial.println("Reset Direction");
      break;
      /*
    default:
      Serial.println("Unknow argument\nF -> run forward\nS -> stop\nR -> turn right\nL -> turn left");
      break;*/
  }
  
  delay(250);
}
