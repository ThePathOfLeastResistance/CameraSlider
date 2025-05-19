
#include <Wire.h>

#include <AccelStepper.h>

AccelStepper stepper1(1, 2, 5); // (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 3, 6);

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

  stepper1.setMaxSpeed(1000); // Set maximum speed value for the stepper
  stepper1.setAcceleration(500); // Set acceleration value for the stepper
  stepper1.setCurrentPosition(0); // Set the current position to 0 steps

  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500);
  stepper2.setCurrentPosition(0);
  
}

void loop() {
  buttonFState = digitalRead(13);
  buttonBState = digitalRead(12);
//  Serial.println(buttonFState);
//  Serial.println(buttonBState);
  int xValue1 = analogRead(A1);
  int yValue1 = analogRead(A0);
  int xValue2 = analogRead(A2);
  int yValue2 = analogRead(A3);
  
  Serial.print("x = ");
  Serial.print(xValue1);
  Serial.print(", y = ");
  Serial.println(yValue1);
  delay(200);

  
   stepper1.moveTo(800); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
  stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position

  stepper2.moveTo(1600);
  stepper2.runToPosition();

  // Move back to position 0, using run() which is non-blocking - both motors will move at the same time
  stepper1.moveTo(0);
  stepper2.moveTo(0);
  while (stepper1.currentPosition() != 0 || stepper2.currentPosition() != 0) {
    stepper1.run();  // Move or step the motor implementing accelerations and decelerations to achieve the target position. Non-blocking function
    stepper2.run();
    //
    //
  }
}
