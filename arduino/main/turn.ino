// STATE for a turn

/*
This fucntion administers steering the vehicle when making a turn
*/
int turnVehicle(int target_heading) {
  
  int cur_heading = getHeading(); //get current heading of vehicle 
  turnRight(); //turn the steering servo to the target heading

  while(!checkTurn(cur_heading, target_heading)){

    runMotor(turnSpeed); //drive forward for 0.25 seconds
    delay(250);
    runMotor(STOP);
    cur_heading = getHeading();
  }
  //once our current heading matches the target heading, we center the steering
  centerWheels();

  //drive forward now that the turn is complete
  driveForwards();
}

boolean checkTurn (int cur_heading, int targ_heading) {
   if(abs(cur_heading - targ_heading) >= 10){
     return false;
   }
   return true;
}

