#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;

int Offset_x  = 154.80; // mG
int Offset_y  = 266.58; // mG
int Offset_z  = 343.81; // mG

void setup() {
  Wire.begin();
  compass = HMC5883L();
  compass.SetMeasurementMode(Measurement_Continuous);
//  compass.SetMeasurementRate(Hz75);

  Serial.begin(9600);

}

void loop() {
   MagnetometerRaw raw = compass.ReadRawAxis();
  
 /*We can measure the heading with x and y coorediantes when the magnetometer
  is level, then correct for signs of axis*/
  float heading = atan2(raw.YAxis + Offset_y, raw.XAxis + Offset_x);
//  float heading = atan2(raw.YAxis, raw.XAxis);

   if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 

  Serial.println(headingDegrees);
  delay(100);
}
