
//Libs
#include <Wire.h>
#include <AccelStepper.h>

AccelStepper stepper1(1, 2, 3); // (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 4, 5);
AccelStepper stepper2(1, 6, 7);

int FStatePin = 12;
int BStatePin = 11;
int LimitSwitchPin = 10;


#define VRX_PIN  A1
#define VRY_PIN  A0

int M1SpeedPin = A2;
int M2SpeedPin = A3;
int M3SpeedPin = A4;


int buttonFState = 0;
int buttonBState = 0;

int button1MState = 0;
int button2MState = 0;
int button3MState = 0;


int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis




//https://docs.arduino.cc/built-in-examples/digital/InputPullupSerial/

void setup() {
  pinMode(FStatePin, INPUT_PULLUP);
  pinMode(BStatePin, INPUT_PULLUP);
  pinMode(CalbriationPin, INPUT_PULLUP);
    
  Serial.begin(9600);

  stepper1.setMaxSpeed(1023); 
  stepper1.setAcceleration(500);
  stepper1.setCurrentPosition(0);

  stepper2.setMaxSpeed(1023);
  stepper2.setAcceleration(500);
  stepper2.setCurrentPosition(0);

  stepper3.setMaxSpeed(1023);
  stepper3.setAcceleration(500);
  stepper3.setCurrentPosition(0);

  while(digitalRead(LimitSwitchPin) == 1){
    stepper1.setSpeed(1000);
    stepper1.runSpeed();
    stepper1.setCurrentPosition(0);
  }

  stepper1.moveTo(-200);
  stepper1.runToPosition(); 

// Make The LED Green
}

void loop() {

  buttonFState = digitalRead(13);
  buttonBState = digitalRead(12);

  //  Serial.println(buttonFState);
//  Serial.println(buttonBState);
  int xValue1 = analogRead(A1);
//  int yValue1 = analogRead(A0);
//  int xValue2 = analogRead(A2);
  int yValue2 = analogRead(A3);

  
  if(buttonFState == 0 && buttonFState == 0){
    stepper1.setSpeed(0);
   } else if (buttonFState == 0 && buttonFState != 0) {
      stepper1.setSpeed(digitalRead(M1SpeedPin));
    } else if (buttonFState != 0 && buttonFState == 0) {
      stepper1.setSpeed(-digitalRead(M1SpeedPin));
    } else {
         stepper1.setSpeed(0);
      }



//FInd the abs value of the thing
// FInd the values that it is returning
  if( xValue1 - 500 < 20 || xValue1 < 20) {
    stepper2.setSpeed(0);
  } else {
    stepper2.setSpeed( digitalRead(M2SpeedPin) *   (xValue1 - 500)/1000  )
    } 

  if( xValue1 - 500 < 20 || xValue1 < 20) {
    stepper2.setSpeed(0);
  } else {
    stepper2.setSpeed( digitalRead(M2SpeedPin) *   (xValue1 - 500)/1000  )
    } 

  if( yValue1 - 500 < 20 || yValue1 < 20) {
    stepper3.setSpeed(0);
  } else {
    stepper3.setSpeed( digitalRead(M2SpeedPin) *   (xValue1 - 500)/1000  )
    } 

  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();
  
  
  
  Serial.print("x = ");
  Serial.print(xValue1);
  Serial.print(", y = ");
  Serial.println(yValue1);
  delay(200);

  
}
