
#include <Servo.h>
#define steering_servo_pin 2

Servo steering_servo;  // create servo object to control a servo

int distance_threshold = 40;

int speed = 210;

void setup() {
  // wait 10 seconds to set up the car
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  Serial.println("ready to run");

  steering_servo.attach(steering_servo_pin);
  centerWheels();
  
  delay(5000);
  digitalWrite(13, LOW);
}

void loop() {

  runMotor(speed);

  while (checkObstacle(distance_threshold)) {
    // it's all good   :-)
    delay(50);
  }

  // power backwards for 5 seconds
  runMotor(- speed);
  delay(4000);

}
