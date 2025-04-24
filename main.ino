
#include <Wire.h>

int buttonFState = 0;
int buttonBState = 0;



#define VRX_PIN  A1 // Arduino pin connected to VRX pin
#define VRY_PIN  A0 // Arduino pin connected to VRY pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonFState = digitalRead(13);
  buttonBState = digitalRead(12);
  Serial.println(buttonFState);
  Serial.println(buttonBState);
  int xValue = analogRead(A1);
  int yValue = analogRead(A0);
  
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(200);
  

}
