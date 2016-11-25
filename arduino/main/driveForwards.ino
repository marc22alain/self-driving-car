// STATE: driving forwards
void driveForwards() {
  // First check that the wheels are straight
  if (steering_servo.read() != 90) {
    assertionError();
  }
  runMotor(speed);
  while (checkObstacle()) {
    delay(100);
  }
  runMotor(STOP);
  brakeFromForwards();
  scanForRoute();
}

void brakeFromForwards() {
  runMotor(- speed);  
  delay(100);
}

