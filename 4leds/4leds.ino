

void setup() {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);      // Open serial channel at 9600 baud rate
}

void loop() {
 if(Serial.available() > 0){
  int var = Serial.read();
  if(var=='1'){
    digitalWrite(5, HIGH);
    
    delay(2000);
  }
  if(var=='2'){
    digitalWrite(6, HIGH);
    
    delay(2000);
  }
 if(var=='3'){
    digitalWrite(7, HIGH);
    
    delay(2000);
  }
   if(var=='4'){
    digitalWrite(8, HIGH);
    
    delay(2000);
  }
 }
              
}
