// STATE for a turn

/* This function administers steering the vehicle when making a turn
 *  Requires: - heading values relative to the car's orientation: 90 is dead ahead
 *            - right-hand turn: 0 <= target_heading < 90
 *            - left-hand turn: 90 < target_heading <= 180
*/
int turnVehicle(int optimumDistance) {
  Serial.println("TURN RIGHT");

  // blink();
  

  turnWheelsRight(); //turn the steering servo to the right

  delay(100);

  // Gun it to get up to speed
  runMotor( min(2 * turnSpeed, 255));
  delay(200);

  // Set to normal turning speed
  runMotor(turnSpeed);

  while(abs(multiSample() - optimumDistance) >= 50){
    Serial.println("STARTING TURN");

    if (multiSample() < turn_distance_threshold) {
      runMotor(STOP);
      brakeFromForwards();
      centerWheels();
      driveBackwards(.5);
    }
  }

  while(abs(multiSample() - optimumDistance) < 50){
    // do nothing
  Serial.println("FINISHING TURN");
  }
  runMotor(STOP);
  // We do this to have a more predictable acceleration.
  brakeFromForwards();
  //once our current heading matches the target heading, we center the steering
  centerWheels();

  delay(100); // because the servo rotation rate is 60 degrees/.12 seconds @ 4.8V

  // If the car turn ends outside of the tolerance, then stop it NOW !
  // This can occur due to momentum carrying the car through the turn
  // before the wheels have straigthened out.
  // *** This assertion is nullified due to the unpredictability of rangefinder sensing.
  // *** In practice, the assertion is called too often, and we have no solution.
//  if (multiSample() < distance) {
//    assertionError();
//  }

  //drive forward now that the turn is complete
  driveForwards();
}


/*
 * Turning left is used as a strategy to get out of a situation where a right turn
 * is not possible. I.e., scanForRoute state only finds obstacles, and must back-up.
 * If it backs up twice and still finds an obstacle, then it calls this function to
 * make a short left turn then transition to the driveForwards state.
 */
void turnLeft() {
  Serial.println("TURN LEFT");
  timesBackedUp = 0;
  int currentHeading = getHeading();
  turnWheelsLeft();
  
  delay(100);

  // Gun it to get up to speed
  runMotor( min(2 * turnSpeed, 255));
  delay(200);

  // Set to normal turning speed
  runMotor(turnSpeed);
  while (getHeading() > currentHeading - 30) {

    if (multiSample() < turn_distance_threshold) {
      runMotor(STOP);
      brakeFromForwards();
      centerWheels();
      // State transition
      driveBackwards(.5);
    }

    delay(15);
  }
  runMotor(STOP);

  //once our current heading matches the target heading, we center the steering
  centerWheels();

  delay(100);

  // State transition
  driveForwards();
}

