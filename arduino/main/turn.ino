// STATE for a turn

/* This function administers steering the vehicle when making a turn
 *  Requires: - heading values relative to the car's orientation: 90 is dead ahead
 *            - right-hand turn: 0 <= target_heading < 90
 *            - left-hand turn: 90 < target_heading <= 180
*/
int turnVehicle(int optimumDistance) {

  // blink();
  

  turnWheelsRight(); //turn the steering servo to the right

  delay(100);

  // Gun it to get up to speed
  runMotor( min(2 * turnSpeed, 255));
  delay(200);

  // Set to normal turning speed
  runMotor(turnSpeed);

  while(abs(multiSample() - optimumDistance) >= 50){

    if (multiSample() < turn_distance_threshold) {
      runMotor(STOP);
      brakeFromForwards();
      centerWheels();
      driveBackwards(.5);
    }
  }

  while(abs(multiSample() - optimumDistance) < 50){
    // do nothing
  }
  runMotor(STOP);
  // brakeFromForwards();
  //once our current heading matches the target heading, we center the steering
  centerWheels();

  delay(100); // because the servo rotation rate is 60 degrees/.12 seconds @ 4.8V

  // If the car turn ends outside of the tolerance, then stop it NOW !
  // This can occur due to momentum carrying the car through the turn
  // before the wheels have straigthened out.
//  if (multiSample() < distance) {
//    assertionError();
//  }

  //drive forward now that the turn is complete
  driveForwards();
}

void turnLeft() {
  int currentHeading = getHeading();
  turnWheelsLeft();
  
  delay(100);

  // Gun it to get up to speed
  runMotor( min(2 * turnSpeed, 255));
  delay(200);

  // Set to normal turning speed
  runMotor(turnSpeed);
  while (getHeading() > currentHeading - 30) {
    delay(15);
  }
  runMotor(STOP);
  // brakeFromForwards();
  //once our current heading matches the target heading, we center the steering
  centerWheels();

  delay(100);

  driveForwards();
}

