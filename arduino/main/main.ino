#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#define steering_servo_pin 2
#define ranging_servo_pin 4
#define setup_LED_pin 13

#define STOP 0

Servo steering_servo;  // create servo object to control a servo
// create a servo object to control a the range finder servo
Servo ranging_servo;  

/* Create a HMC5883 magnetosensor object and asssing
assign a unique ID to this sensor */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);


// Define a few GLOBAL VARIABLES
// we may want an interface to adjust these at the device,
// to save continually reprogramming the Arduino
int distance_threshold = 40;
int speed = 150;
int turnSpeed = 170;

void setup() {
  
  steering_servo.attach(steering_servo_pin);
  ranging_servo.attach(ranging_servo_pin);
  centerWheels();
  centerRangeFinder();

  /* Initialise the compass */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    while(1);
  }
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




