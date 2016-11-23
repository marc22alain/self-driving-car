
/*
 * This function stops the car at the point of some error, identified by some assertion.
 */
void assertionError() {
  digitalWrite(setup_LED_pin, HIGH);
  runMotor(STOP);
  while (1) {
    // done
  }
}

