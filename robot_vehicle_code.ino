// THIS SECTION FOR THE ROBOT VEHICLE
//__________________________________________________________________________________________

// include the SoftwareSerial library so you can use its functions:
#include <SoftwareSerial.h>
#include <Servo.h>
// Servos are connectd to PWM Pins 9 and 10.

SoftwareSerial mySerial(9,10);  // Rx, Tx
Servo tilt, pan; // create servo object to control a servo 

int xPos;
int yPos;
int inPin9 = 9;   // first input set to pin 9
int inPin10 = 10;   // second input set to pin 10
int val9 = 0;     // variable to store the read value
int val10 = 0;     // variable to store the read value
int buttonState = 0;

void setup()
{
    //tilt.attach(9); // attaches the tilt servo on pin 9 to the servo object 
  // pan.attach(10); // attaches the pan servo on pin 10 to the servo object 
  
  int x, y; // variables to read the values from the analog pins 

  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(inPin9, INPUT);      // sets the digital pin A0 as input
  pinMode(inPin10, INPUT);      // sets the digital pin A1 as input
}

void loop()
{
  val9 = digitalRead(inPin9);   // read the input pin 9
  xPos = map(val9, 0, 1023, 0, 5); // scale it to use with the servo b/w 900 usec to 2100 usec
  
  val10 = digitalRead(inPin10);   // read the input pin 10
  yPos = map(val10, 0, 1023, 0, 5); // scale it to use with the servo b/w 900 usec to 2100 usec
  
  buttonState = digitalRead(buttonState);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonState, INPUT_PULLUP); 


 // USE THIS TO VIEW IN/OUT VALUES 

  Serial.print("X: ");
  Serial.print(val9);
  Serial.print(" | Y: ");
  Serial.print(val10);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  delay(1000);
}

/*
void loop()
{ 
  x = analogRead(x);
  xPosition = map(x, 0, 1023, 0, 5); // scale it to use with the servo b/w 900 usec to 2100 usec
  y = analogRead(y);
  yPosition = map(y, 0, 1023, 0, 5);
  //tilt.write(xPosition); // sets the servo position according to the scaled value 
  //pan.write(yPosition);
  
  buttonState = digitalRead(buttonState);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(500); // add some delay between reads

  
 // delay(15); // waits for the servos to get there 
}
*/
