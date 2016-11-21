#define pos_dir 11
#define neg_dir 3

void runMotor (int speed) {
  if (speed >= 0 && speed < 256) {
    // first set the opposite direction to 0
    analogWrite(neg_dir, 0);
    // now set the desired direction
    analogWrite(pos_dir, speed);
  }
  else if (speed > -256) {
    // first set the opposite direction to 0
    analogWrite(pos_dir, 0);
    // now set the desired direction
    analogWrite(neg_dir, - speed);
  }
}
