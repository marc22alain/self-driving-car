
/*
 * This function stops the car at the point of some assertion error.
 */
void assertionError() {
  digitalWrite(setup_LED_pin, HIGH);
  runMotor(STOP);
  while (1) {
    // done; humans must intervene
  }
}


void blink() {
  digitalWrite(setup_LED_pin, HIGH);
  delay(500);  
  digitalWrite(setup_LED_pin, LOW);
  delay(500);  
  digitalWrite(setup_LED_pin, HIGH);
  delay(500);  
  digitalWrite(setup_LED_pin, LOW);
}

