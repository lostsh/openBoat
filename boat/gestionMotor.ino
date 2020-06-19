void run(){
  run(255);
}
void stop(){
  analogWrite(motorPin, 0);
}
void run(int motorSpeed){
  analogWrite(motorPin, motorSpeed);
}
