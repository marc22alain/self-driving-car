void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready to read");
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  Serial.println(reading);
  delay(100);
}
