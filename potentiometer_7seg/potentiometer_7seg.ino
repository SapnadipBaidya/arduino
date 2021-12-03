

int disp_pin[7];  /* array for a-g pins of 7-Segment display */

void define_segment_pins(int a, int b, int c, int d, int e, int f, int g) /* Assigns 7-segment display pins to board */
{  
  disp_pin[0] = a;
  disp_pin[1] = b;
  disp_pin[2] = c;
  disp_pin[3] = d;
  disp_pin[4] = e;
  disp_pin[5] = f;
  disp_pin[6] = g;
}
int potPin1 = A0;

void display_number(char num)  /* Function for displaying number (0-9) */
{
  switch(num)
  {
    case H:
    digitalWrite(disp_pin[0],HIGH ); /* Drive disp_pin[0] to LOW */
    digitalWrite(disp_pin[1],LOW ); /* Driving LOW turns on LED segment for common anode display */
    digitalWrite(disp_pin[2],LOW );
    digitalWrite(disp_pin[3],HIGH );
    digitalWrite(disp_pin[4],LOW );
    digitalWrite(disp_pin[5],LOW );
    digitalWrite(disp_pin[6],LOW ); 
    break;
    case E:
    digitalWrite(disp_pin[0], LOW);  /* Drive disp_pin[7] to HIGH */
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);  /* Driving HIGH turns off LED segment for common anode display */
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case L:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], HIGH);
    break;
    
    default:
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
  }
}
void setup()
{

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
   pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  define_segment_pins(12,11,10,9,8,7,6);  /* a-g segment pins to Arduino */
pinMode(potPin1, INPUT);

}

void loop()
{ // send data only when you receive data:
  if (Serial.available() > 0) {
    
     if(analogRead(potPin1)>0 && analogRead(potPin1)<99)
  {
   display_number('L');
  }

  if(analogRead(potPin1)>100 && analogRead(potPin1)<499)
  {
   display_number('E');
  }

  if(analogRead(potPin1)>500 && analogRead(potPin1)<1024)
  {
  display_number('H');
  }
    
  }

 

  delay(3000);

}
