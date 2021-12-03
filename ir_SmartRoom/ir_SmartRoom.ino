// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12); //rs,enable,d4,d5,d6,d7
 int led = 6;

void setup()
{
pinMode(led, OUTPUT);
  // set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.clear();

  pinMode(13,OUTPUT);
  pinMode(3,INPUT);//used for entry count
  pinMode(5,INPUT);//used for exit count
  Serial.begin(9600);
}
void loop()
{
 int count=0;

  if (digitalRead(3)== HIGH)
  {
    count++;
    
    delay(10);
  }
  else if (digitalRead(5)== HIGH) 
  {
    
    count--;
    delay(10);
    
  }
lcd.setCursor(0,0);
 if(count>0){
  digitalWrite(led, HIGH);
  lcd.print("people inside: "); // Prints count value: to LCD
  lcd.print(count);
  }
  else{
    digitalWrite(led, LOW);
    lcd.print("No person inside ");
  }
  
}
  

  
  
