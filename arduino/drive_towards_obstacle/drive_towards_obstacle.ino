
#include <Servo.h>
#define steering_servo_pin 3

Servo steering_servo;  // create servo object to control a servo

int distance_threshold = 40;

int speed = 120;

void setup() {
  // wait 10 seconds to set up the car
  Serial.begin(9600);
  Serial.println("ready to run");

  steering_servo.attach(steering_servo_pin);
  
  delay(10000);
}

void loop() {

  runMotor(speed);

  while (checkObstacle(distance_threshold)) {
    // it's all good   :-)
    delay(50);
  }

  // power backwards for 5 seconds
  runMotor(- speed);
  delay(2000);

}
