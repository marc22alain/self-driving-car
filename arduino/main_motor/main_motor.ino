
#define pos_dir 10
#define neg_dir 9

void setup() {
  Serial.begin(9600);
  Serial.println("Ready to receive command");
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
    if (val == '-') {
      while (!Serial.available()) { 
        // busy wait
      }
      val = Serial.read();
      runMotor(val, -1);
    }
    else {
      runMotor(val, 1);    
    }
  }
}

void runMotor (char val, int dir) {
  int speed = val - '0'; // clever char to int conversion
  if (dir > 0) {
    // first set the opposite direction to 0
    analogWrite(neg_dir, 0);
    // now set the desired direction
    analogWrite(pos_dir, speed * 28);
    Serial.println("move forward");
  }
  else {
    // first set the opposite direction to 0
    analogWrite(pos_dir, 0);
    // now set the desired direction
    analogWrite(neg_dir, speed * 28);
    Serial.println("move backward");
  }
}

