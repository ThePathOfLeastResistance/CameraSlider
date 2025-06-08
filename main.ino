const int xStepPin = 2;
const int xDirPin = 5;
const int yStepPin = 3;
const int yDirPin = 6;
const int ledPin = 13;
const int joyXPin = A0;
const int joyYPin = A1;

void setup() {
  pinMode(xStepPin, OUTPUT);
  pinMode(xDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(joyXPin, INPUT);
  pinMode(joyYPin, INPUT);
}

void loop() {
  int joyXVal = analogRead(joyXPin);
  int joyYVal = analogRead(joyYPin);

  if (joyXVal > 512) {
    digitalWrite(xDirPin, HIGH);
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(xStepPin, LOW);
    delayMicroseconds(1000);
  } else if (joyXVal < 512) {
    digitalWrite(xDirPin, LOW);
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(xStepPin, LOW);
    delayMicroseconds(1000);
  }

  if (joyYVal > 512) {
    digitalWrite(yDirPin, HIGH);
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(yStepPin, LOW);
    delayMicroseconds(1000);
  } else if (joyYVal < 512) {
    digitalWrite(yDirPin, LOW);
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(yStepPin, LOW);
    delayMicroseconds(1000);
  }


}
