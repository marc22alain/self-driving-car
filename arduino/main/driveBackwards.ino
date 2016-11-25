// STATE for driving backwards

/*
 * For a couple of seconds, run the motor backwards (reverse direction travel)
 */
void driveBackwards(float factor) {
  // First check that the wheels are straight
  if (steering_servo.read() != 90) {
    assertionError();
  }
  // Gun it to get up to speed
  runMotor( - min(2 * speed, 255));
  delay(200);

  // Set to cruising speed
  runMotor(- speed);
  delay((int)(1000 + factor));
  runMotor(STOP); // stop motor
  brakeFromBackwards();

  // Transition to next state
  scanForRoute();//scan for a viable route
}

void brakeFromBackwards() {
  runMotor(speed);  
  delay(100);
  runMotor(STOP);
}

