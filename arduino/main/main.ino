#include <Servo.h>
#include <Wire.h>
#include <HMC5883L.h>

#define steering_servo_pin 2
#define ranging_servo_pin 4
#define setup_LED_pin 13

#define STOP 0

Servo steering_servo;  // create servo object to control a servo
// create a servo object to control a the range finder servo
Servo ranging_servo;  

HMC5883L compass;

int Offset_x  = 154.80; // mG
int Offset_y  = 266.58; // mG
int Offset_z  = 343.81; // mG


// Define a few GLOBAL VARIABLES
// we may want an interface to adjust these at the device,
// to save continually reprogramming the Arduino
int distance_threshold = 45;
int turn_distance_threshold = min(15, distance_threshold / 3);
int speed = 150;
int turnSpeed = 150;
int currentSpeed = 0;           // stores the car's current speed
int rangefinder_servo_pos = 0;  // stores the rangefinder servo's current position
int steer_servo_pos = 0;        // stores the steering servo's current position

void setup() {
  
  steering_servo.attach(steering_servo_pin);
  ranging_servo.attach(ranging_servo_pin);
  centerWheels();
  centerRangeFinder();

  Wire.begin();
  compass = HMC5883L();
  compass.SetMeasurementMode(Measurement_Continuous);
  compass.SetMeasurementRate(Hz75);
  
  // turn on the setup indicator LED
  // and wait 10 seconds to set up the car
  pinMode(setup_LED_pin, OUTPUT);
  digitalWrite(setup_LED_pin, HIGH);
  delay(10000);
  digitalWrite(setup_LED_pin, LOW);

}

void loop() {
  // this is the initial state
  driveForwards();

}




