// STATE: scanning with range-finder for a clear route
void scanForRoute() {
  int bestHeadingChange = -1;
  int optimum_dis = analogRead(A0);

  do {
    delay(100);
    int sensorValue = analogRead(A0);
    if (sensorValue > optimum_dis && sensorValue >= distance_threshold) {
      optimum_dis = sensorValue;
      bestHeadingChange =  rangefinder_servo_pos;
    }
    turnRangefinder();
  } while (rangefinder_servo_pos > 0);

  // note that this resets rangefinder_servo_pos to rangefinder_servo_default_pos (90 degrees)
  centerRangeFinder();  

  /*After scanning when a target heading is found we make a turn 
  turn*/
  if (bestHeadingChange > 0) {
    turnVehicle(bestHeadingChange);
  }
  
  else{
    //if no clear route is found, the vehicle needs to back up
    driveBackwards();
  }
}

