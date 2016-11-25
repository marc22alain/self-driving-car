
/* Device-specific functions for the steering servo
 * NB: the steering servo is physically range-restricted
 *     to 20 - 180 degrees
 */
int default_steer_servo_pos = 90;    // variable to store the servo position

int rangefinder_servo_default_pos = 90;


void centerWheels () {
  steer_servo_pos = default_steer_servo_pos;
  steering_servo.write(steer_servo_pos);
}

/*
 * This function is used in the turn state to make a turn the vehicle towards
 * the right heading
 */
void turnWheelsRight(){
  steer_servo_pos = 20;
  steering_servo.write(steer_servo_pos);
}

/*
 * This function turns the range finder servo 10 degrees to the right,
 * reading from the range finder after each turn. 
 * It returns the reading from the range finder after a turn
 */
void turnRangefinder() {
  rangefinder_servo_pos -= 10;
  if(rangefinder_servo_pos == -10){
    return;
  }
  ranging_servo.write(rangefinder_servo_pos);
}

void centerRangeFinder () {
  rangefinder_servo_pos = rangefinder_servo_default_pos;
  ranging_servo.write(rangefinder_servo_pos);
}
