const int sensorPin = A0;
const int knobPin = A2;
const int peizoPin = 8;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  int knobValue = analogRead(knobPin);
  int pitchHigh = map(knobValue, 0, 1023, 50, 4000);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, pitchHigh);
  tone(peizoPin, pitch, 20);
  delay(10);
}
