#define pos_dir 11
#define neg_dir 3

void runMotor (int setSpeed) {
  if (setSpeed >= 0 && setSpeed < 256) {
    // first set the opposite direction to 0
    analogWrite(neg_dir, STOP);
    // now set the desired direction
    analogWrite(pos_dir, setSpeed);
  }
  else if (setSpeed > -256) {
    // first set the opposite direction to 0
    analogWrite(pos_dir, STOP);
    // now set the desired direction
    analogWrite(neg_dir, - setSpeed);
  }
}
