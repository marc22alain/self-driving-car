

bool checkObstacle() {
  int sensorValue = analogRead(A0);
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


