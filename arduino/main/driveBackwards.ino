// STATE for driving backwards
void driveBackwards(float factor) {
  // for a couple of seconds, run the motor backwards (reverse direction travel)
  runMotor(- speed);
  delay((int)(2000 + factor));
  runMotor(STOP); // stop motor
  brakeFromBackwards();
  scanForRoute();//scan for a viable route
}

void brakeFromBackwards() {
  runMotor(speed);  
  delay(100);
  runMotor(STOP);
}

