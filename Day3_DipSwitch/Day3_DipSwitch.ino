int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

int sensorPin = A0;
int sensorValue = 0;

void showLightLevel() {
  // Low light level, LED1 On/Off
  if (analogRead(sensorPin) >= 50) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  // Mid light level, LED2 On/Off
  if (analogRead(sensorPin) >= 21 && analogRead(sensorPin) <= 49) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  // High light level, LED3 On/Off
  if (analogRead(sensorPin) <= 20) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);
  
  showLightLevel();
}
