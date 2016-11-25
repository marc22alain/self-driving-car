// STATE: driving forwards

/*
 * Drive forwards until an obstacle is detected.
 * Depends on sane speed settings so that there is no collision with the obstacle.
 */
void driveForwards() {
  // First check that the wheels are straight
  if (steering_servo.read() != 90) {
    assertionError();
  }
  // Gun it to get up to speed
  runMotor( min(2 * speed, 255));
  delay(200);

  // Set to cruising speed
  runMotor(speed);

  while (checkObstacle()) {
    delay(100);
  }
  runMotor(STOP);
  brakeFromForwards();

  // Transition to next state
  scanForRoute();
}

void brakeFromForwards() {
  runMotor(- speed);  
  delay(100);
  runMotor(STOP);
}

