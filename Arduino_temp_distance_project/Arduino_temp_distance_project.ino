

void setup() {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);      // Open serial channel at 9600 baud rate
}

void loop() {
 if(Serial.available() > 0){
  int var = Serial.read();
  if(var=='1'){
    analogWrite(5,64);
    analogWrite(6,64);
    delay(200);
  }
  if(var=='2'){
    analogWrite(5,128);
    analogWrite(6,128);
    delay(200);
  }
  if(var=='3'){
    analogWrite(5,255);
    analogWrite(6,255);
    delay(200);
  }
 }
              
}
