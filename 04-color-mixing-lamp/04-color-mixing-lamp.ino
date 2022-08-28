const int redLedPin = 11;
const int greenLedPin = 10;
const int blueLedPin = 9;

const int redSensonPin = A0;
const int greenSensonPin = A1;
const int blueSensonPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensonPin);
  delay(5);
  greenSensorValue = analogRead(greenSensonPin);
  delay(5);
  blueSensorValue = analogRead(blueSensonPin);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);

}