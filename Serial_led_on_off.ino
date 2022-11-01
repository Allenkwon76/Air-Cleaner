void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char data;
  if(Serial.available()){
    data = Serial.read();
    }
    if(data == '1'){
      digitalWrite(13, HIGH);
      Serial.println("led on");
      }
    if(data == '2'){
      digitalWrite(13, LOW);
      Serial.println("led OFF");
      }

}
