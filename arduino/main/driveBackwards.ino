// STATE for driving backwards
void driveBackwards() {
  // for a couple of seconds, run the motor backwards (reverse direction travel)
  runMotor(- speed);
  delay(2000);
  runMotor(STOP); // stop motor
  scanForRoute();//scan for a viable route
}


