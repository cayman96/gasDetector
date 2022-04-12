void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float val = analogRead(A0);
  float vtg = val*(5.0/1023.0);
  Serial.println(vtg);
  if(vtg > 3.0){
    Serial.println("ALARM!");
    }
  delay(500);
}
