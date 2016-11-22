// STATE: scanning with range-finder for a clear route
void scanForRoute() {
  int bestHeading = -1;
  int optimum_dis = analogRead(A0);
  int heading = 0;

  do {
    delay(100);
    int sensorValue = analogRead(A0);
    if (sensorValue > optimum_dis && sensorValue >= distance_threshold) {
      optimum_dis = sensorValue;
      bestHeading =  heading;
    }
    heading = turnRangefinder();
  } while (heading > 0);

  centerRangeFinder();

  /*After scanning when a target heading is found we make a turn 
  turn*/
  if (bestHeading > 0) {
    turnVehicle(bestHeading);
  }
  
  else{
    //if no clear route is found, the vehicle needs to back up
    driveBackwards();
  }
}

