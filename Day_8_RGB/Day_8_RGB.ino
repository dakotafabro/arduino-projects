int blue = 9;
int green = 10;
int red = 11;

void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  RGB_color(125, 0, 0);
  delay(1000);
  RGB_color(0, 125, 0);
  delay(1000);
  RGB_color(0, 0, 125);
  delay(1000);
  RGB_color(125, 0, 125);
  delay(1000);
  RGB_color(125, 125, 125);
  delay(1000);
}
