/* In this sketch we define and implement getHeading() which returns 
the current heading of the vehicle*/

int getHeading(){
  MagnetometerRaw raw = compass.ReadRawAxis();
  
 /*We can measure the heading with x and y coorediantes when the magnetometer
  is level, then correct for signs of axis*/
  float heading = atan2(raw.YAxis + Offset_y, raw.XAxis + Offset_x);
  
  /* Once you have your heading, you must then add your 'Declination Angle', 
   which is the 'Error' or angle variation between magnetic North and 
   and true north (the direction along a meridian towards the geographic North Pole)*/ 
  //Found here: http://www.magnetic-declination.com/
  //Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  float declinationAngle = -.175;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 

  return headingDegrees;
}
