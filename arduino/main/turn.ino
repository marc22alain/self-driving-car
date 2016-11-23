// STATE for a turn

/* This function administers steering the vehicle when making a turn
 *  Requires: - heading values relative to the car's orientation: 90 is dead ahead
 *            - right-hand turn: 0 <= target_heading < 90
 *            - left-hand turn: 90 < target_heading <= 180
*/
int turnVehicle(int headingChange) {
  
  int cur_heading = getHeading(); //get current heading of vehicle 
  int target_heading = cur_heading + (90 - headingChange);

  // adjust for out-of-quadrant values
  if (target_heading >= 360) {
    target_heading -= 360;
  }
  else if (target_heading < 0) {
    target_heading += 360;
  }

  turnRight(); //turn the steering servo to the right

  while(abs(cur_heading - target_heading) >= 10){

    runMotor(turnSpeed);
    delay(67);          // since the default refresh rate is 15Hz, and we haven't changed it
    cur_heading = getHeading();
  }
  runMotor(STOP);
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

