int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

int sensorPin = A0;
int sensorValue = 0;

unsigned int newBatteryLevel = 0;
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;

int PrintBatteryPercentage() {
  int newBatteryLevel = ((double)batteryLevel / (double)batteryCapacity) * 100;

  Serial.print(newBatteryLevel);
  Serial.println("%");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(batteryLevel);
  Serial.println("%");
  
  sensorValue = 1;
  batteryLevel += sensorValue;


  if (batteryLevel <= 39) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  
  if (batteryLevel >= 40 && batteryLevel <= 99) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  
  if (batteryLevel >= 100) {
    digitalWrite(LED3, HIGH);
    Serial.println("Fully Charged!");
    batteryLevel = 100;
  } else {
    digitalWrite(LED3, LOW);
  }

  delay(200);
}
