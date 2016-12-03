#include <Servo.h>
#define servo_pin 4

Servo servo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position


void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_pin);
  Serial.begin(9600);
  Serial.println("At your command:");

}

void loop() {
  pos = parseForNumber();
  if (pos >= 0 && pos <= 180) {
    servo.write(pos);  
    Serial.println("Command received and delegated!");
  }
  else {
    Serial.println("Command received ... but it's invalid!");
  }
  delay(200);
  checkObstacle();
}
