int red = 11;
int green = 10;
int blue = 9;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;

int sensorPin = A0;
int sensorValue = 0;

void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

double getBatteryPercentage() {
  return ((double)batteryLevel / (double)batteryCapacity) * 100;
}

void setup() {
  // put your setup code here, to run once:
 pinMode(red, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(blue, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue;

  double percentage = getBatteryPercentage();

  if (percentage >= 100) {
    RGB_color(0, 125, 0);
    batteryLevel = batteryCapacity;
    percentage = 100; // green
  } else if (percentage > 0 && percentage <=25) {
    RGB_color(125, 0, 0); // red
  } else if (percentage > 25 && percentage <= 50) {
    RGB_color(125, 88, 0); // yellow
  } else if (percentage > 50 && percentage <= 99) {
    RGB_color(0, 125, 125); // blue
  }

  Serial.print(percentage);
  Serial.println("%");
  Serial.print("sensorValue ");
  Serial.println(sensorValue);
  

  delay(50);
}
