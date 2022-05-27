void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HELLOW!!!!!!!!!");
  analogReference(EXTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  float v = 1023.0/3.3;
  float myV = x/v;
  Serial.println(myV);
  delay(100);
}
