// STATE: scanning with range-finder for a clear route
/*
 * Requires: - rangefinder_servo_pos must decrement to 0
 */
void scanForRoute() {
  Serial.println("SCAN FOR ROUTE");
  int bestHeadingChange = -1;
  int optimum_dis = multiSample();
  int sensorValue;
  do {
    delay(100);
    sensorValue = multiSample();
    if (sensorValue > optimum_dis && sensorValue >= distance_threshold) {
      optimum_dis = sensorValue;
      bestHeadingChange =  rangefinder_servo_pos;
    }
    turnRangefinder();
  } while (rangefinder_servo_pos > 0);

  // note that this resets rangefinder_servo_pos to rangefinder_servo_default_pos (90 degrees)
  centerRangeFinder();  

  /* After scanning when a target heading is found we make a turn. */
  if (optimum_dis > 3 * distance_threshold) {
    turnRight(optimum_dis);
  }
  else{
    //if no clear route is found, the vehicle needs to back up
    if (timesBackedUp == 2) {
      turnLeft();
    }
    else {
      driveBackwards(1);    
    }
  }
}

