int redLED = 3;
int yellowLED = 5;
int greenLED = 6;

void showRed() {
digitalWrite(redLED, HIGH);
digitalWrite(yellowLED, LOW);
digitalWrite(greenLED, LOW);
}

void showYellow() {
 digitalWrite(redLED, LOW);
digitalWrite(yellowLED, HIGH);
digitalWrite(greenLED, LOW);
}

void showGreen() {
digitalWrite(redLED, LOW);
digitalWrite(yellowLED, LOW);
digitalWrite(greenLED, HIGH);
}

void setup() {
  // put your setup code here, to run once:
pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);

pinMode(redLED, LOW);
pinMode(yellowLED, LOW);
pinMode(greenLED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
showRed();
delay(1000);

showYellow();
delay(1000);

showGreen();
delay(1000);
}
