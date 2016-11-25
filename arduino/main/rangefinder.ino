

bool checkObstacle() {
  int sensorValue = multiSample();
  if (sensorValue > distance_threshold) {
//    Serial.print("Clear: ");
//    Serial.println(sensorValue);
    return true;
  }
  else {
//    Serial.print("About to crash: ");
//    Serial.println(sensorValue);
    return false;
  }
}

int multiSample () {
	int total = 0;
	for (int i = 0; i < 16; i++) {
		total += analogRead(A0);
		delay(1);
	}
	return (total >> 4);
}
