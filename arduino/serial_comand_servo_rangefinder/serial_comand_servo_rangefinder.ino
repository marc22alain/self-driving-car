
/* Requires: - serial port already open
 *           - serial message terminated with a new line character
 *
 * Ensures:  - returns an intenger value (possibly negative)
 */
int parseForNumber () {
  // loop guard
  bool done = false;
  bool negative = false;
  int command = 0;
  while (!done) {
    // busy waiting until another char arrives
    if (Serial.available()) {
      
      char letter = Serial.read();
      
      // first check for a negative sign
      // note that this allows the user to type the sign
      // anywhere in their input
      if (letter == '-') {
        negative = true;
      }
      
      // otherwise check if it's a number 
      else if (letter >= '0' && letter <= '9') {
        // clever conversion from char to int
        int digit = letter - '0';
        // shift the currently stored number one decimal place
        command *= 10;
        // now add the new digit to the number
        command += digit;
      }

      // otherwise check if it's the end of the command
      else if (letter = '\n') {
        done = true;
      }

      // otherwise user made a mistake
      else {
        // do nothing, ignore this letter
      }
    }
  }

  // now that command input is complete, apply the sign
  if (negative) {
    command *= -1;
  }

  return command;
}

