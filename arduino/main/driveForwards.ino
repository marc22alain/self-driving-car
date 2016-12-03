// STATE: driving forwards

/*
 * Drive forwards until an obstacle is detected.
 * Depends on sane speed settings so that there is no collision with the obstacle.
 */
void driveForwards() {
  Serial.println("DRIVE FORWARDS");
  timesBackedUp = 0;
  // First check that the wheels are straight
  if (steering_servo.read() != 90) {
    assertionError();
  }
  // Gun it to get up to speed
  runMotor( min(2 * speed, 255));
  delay(200);

  // Set to cruising speed
  runMotor(speed);

  unsigned long startTime = millis();

  while (checkObstacle()) {
    delay(100);
    Serial.println("CRUISING");

    if (millis() > startTime + 750) {
      Serial.println("SLOWING");
      runMotor((int) speed * 0.65);
      digitalWrite(setup_LED_pin, HIGH);
    }
  }
  runMotor(STOP);
  digitalWrite(setup_LED_pin, LOW);
  brakeFromForwards();

  // Transition to next state
  scanForRoute();
}

void brakeFromForwards() {
  runMotor(- speed);  
  delay(200);
  runMotor(STOP);
}

