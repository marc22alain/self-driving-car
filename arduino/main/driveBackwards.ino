// STATE for driving backwards

/*
 * For a couple of seconds, run the motor backwards (reverse direction travel)
 */
void driveBackwards(float factor) {
  // First check that the wheels are straight
  if (steering_servo.read() != 90) {
    assertionError();
  }
  runMotor(- speed);
  delay((int)(2000 + factor));
  runMotor(STOP); // stop motor
  brakeFromBackwards();
  scanForRoute();//scan for a viable route
}

void brakeFromBackwards() {
  runMotor(speed);  
  delay(100);
}

