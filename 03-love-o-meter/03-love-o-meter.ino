const int sensorPin = A0;
float baselineTemp = 20.0;

void setup() {
  // Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Sensor value
  int sensorVal = analogRead(sensorPin);

  // Volts
  float voltage = (sensorVal / 1024.0) * 5.0;

  // degrees C
  float temperature = (voltage - .5) * 100;
  // Serial.println(temperature);

  if (temperature < baselineTemp) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature < baselineTemp + 5) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature < baselineTemp + 10) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(69);
}