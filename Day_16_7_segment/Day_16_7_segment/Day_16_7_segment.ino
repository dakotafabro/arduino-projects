#include <TM1637Display.h>

#define CLK 6
#define DIO 5

TM1637Display display = TM1637Display(CLK, DIO);

const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};

const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};

const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G, // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // o
  SEG_C | SEG_E | SEG_G, // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G // E
};

void setup() {
  // put your setup code here, to run once:
  display.clear();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

  display.setBrightness(7);

  display.setSegments(data);
  delay(1000);
  display.clear();
  delay(1000);

  int i; 
  for (i = 0; i <= 100; i++) {
    display.showNumberDec(i);
    delay(50);
  }

  delay(1000);
  display.clear();
  delay(1000);
  display.setSegments(done);
  while(1);
}
