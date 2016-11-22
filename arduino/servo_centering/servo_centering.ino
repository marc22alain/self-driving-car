/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define steering_servo_pin 2
#define ranging_servo_pin 4

Servo steering_servo;  // create servo object to control a servo
Servo ranging_servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

/*
 * NB: the steering servo is physically range-restricted
 *     to 20 - 180 degrees
 */
int pos = 0;    // variable to store the servo position


void setup() {
  steering_servo.attach(steering_servo_pin);
  ranging_servo.attach(ranging_servo_pin);
  steering_servo.write(90);              // tell servo to go to centered position
  ranging_servo.write(90);              // tell servo to go to centered position
  delay(10000);
    for (pos = 90; pos >= 20; pos -= 1) { // goes from centered position to 0 degrees
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    ranging_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}

void loop() {
//  for (pos = 20; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
//    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    ranging_servo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    ranging_servo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

}

