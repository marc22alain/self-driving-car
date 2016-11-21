#include <Servo.h>
#define steering_servo_pin 2

#define setup_LED_pin 13

Servo steering_servo;  // create servo object to control a servo


// Define a few GLOBAL VARIABLES
// we may want an interface to adjust these at the device,
// to save continually reprogramming the Arduino
int distance_threshold = 40;


void setup() {
  
  steering_servo.attach(steering_servo_pin);
  centerWheels();

  // turn on the setup indicator LED
  // and wait 10 seconds to set up the car
  pinMode(setup_LED_pin, OUTPUT);
  digitalWrite(setup_LED_pin, HIGH);
  delay(10000);
  digitalWrite(setup_LED_pin, LOW);

}

void loop() {
  // this is the initial state
  scanForRoute();

}




