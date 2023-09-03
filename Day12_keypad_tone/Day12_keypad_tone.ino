#include <Key.h>
#include <Keypad.h>

int buzzer = 8;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

const byte ROWS  = 4;
const byte COLS = 4;
const byte PassLength = 4;
char password[PassLength] = {'0', '0', '0', '0'};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void playSuccess() {
  tone(buzzer, 370, 1000);
  RGB_color(0, 125, 0); // blue;
  delay(50);
  noTone(buzzer);
}

void playError() {
  tone(buzzer, 147, 500);
  RGB_color(125, 0, 0);
  delay(50);
  noTone(buzzer);
}

void playInput() {
  tone(buzzer, 880, 250);
  RGB_color(0, 0, 125);
  delay(50);
  noTone(buzzer);
}

void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}

int unlockMode() {
  char customKey = customKeypad.getKey();
  
  Serial.println("Unlock Mode: Type password to continue");
  
  delay(500);

  for (int i = 0; i < PassLength; i++) {
    while(!(customKey = customKeypad.getKey())) {
      // wait infinitely for input
    }
    if (password[i] != customKey) {
      Serial.println("Wrong password");
      Serial.println(customKey);
      playError();
      RGB_color(125, 0, 0);
      return -1;
    }
    Serial.print("*");
    playInput();
  }

  Serial.print("");
  Serial.println("Device Successfully Unlocked");
  playSuccess();
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  RGB_color(125, 125, 125); // LED starts at white

  Serial.begin(9600);
  Serial.println("Press * to set new password or # to access the system.");
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();

  if (customKey = "*") {
    int access = unlockMode();

    if (access < 0) {
      Serial.println("Access Denied. Cannot change password without current or default password.");
      RGB_color(125, 0, 0);
    } else {
      Serial.println("Welcome, Authorized User. Please enter a new password:");
      delay(500);

      for (int i = 0; i <PassLength; i++) {
        while(!(customKey = customKeypad.getKey())) {
          // wait infinitely for input
        }

        password[i] = customKey;
        Serial.print("*");
        playInput();
      }

      Serial.println("");
      Serial.println("Password Successfully Changed!");
      playSuccess();
    }
  }

  if (customKey = "#") {
    int access = unlockMode();

    if (access < 0) {
      Serial.println("Access Denied.");
      
    } else {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
      playSuccess();
    }
  }
}
