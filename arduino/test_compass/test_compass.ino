#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>


/* Create a HMC5883 magnetosensor object and asssing
assign a unique ID to this sensor */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  /* Initialise the compass */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getHeading());
}
