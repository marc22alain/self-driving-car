// STATE: driving forwards
void driveForwards() {
  runMotor(10);
  while (!checkObstacle()) {
    delay(100);
  }
  runMotor(0);
  scanForRoute();
}
