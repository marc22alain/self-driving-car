
/*
 * NB: the steering servo is physically range-restricted
 *     to 20 - 180 degrees
 */
int steer_servo_pos = 0;    // variable to store the servo position


void centerWheels () {
  steer_servo_pos = 90;
  steering_servo.write(steer_servo_pos);
}

