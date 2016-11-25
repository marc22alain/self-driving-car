// STATE for a turn

/* This function administers steering the vehicle when making a turn
 *  Requires: - heading values relative to the car's orientation: 90 is dead ahead
 *            - right-hand turn: 0 <= target_heading < 90
 *            - left-hand turn: 90 < target_heading <= 180
*/
int turnVehicle(int headingChange) {

  blink();
  
  int cur_heading = getHeading(); //get current heading of vehicle 
  int target_heading = cur_heading + (90 - headingChange);

  // adjust for out-of-quadrant values
  if (target_heading >= 360) {
    target_heading -= 360;
  }
  else if (target_heading < 0) {
    target_heading += 360;
  }

  turnWheelsRight(); //turn the steering servo to the right

  delay(1000);

  // Gun it to get up to speed
  runMotor( min(2 * turnSpeed, 255));
  delay(200);

  // Set to normal turning speed
  runMotor(turnSpeed);

  while(abs(cur_heading - target_heading) >= 10){

    if (multiSample() < turn_distance_threshold) {
      runMotor(STOP);
      brakeFromForwards();
      centerWheels();
      driveBackwards(.5);
    }

    delay(15);          // since the default refresh rate is 75Hz, and we haven't changed it
    cur_heading = getHeading();
  }
  runMotor(STOP);
  brakeFromForwards();
  //once our current heading matches the target heading, we center the steering
  centerWheels();

  delay(180); // because the servo rotation rate is 60 degrees/.12 seconds @ 4.8V

  // If the car turn ends outside of the tolerance, then stop it NOW !
  // This can occur due to momentum carrying the car through the turn
  // before the wheels have straigthened out.
  if (abs(cur_heading - target_heading) > 10) {
    assertionError();
  }

  //drive forward now that the turn is complete
  driveForwards();
}

