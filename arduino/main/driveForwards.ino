// STATE: driving forwards
void driveForwards() {
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

