#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

unsigned long timer = 0; //timer

int second = 0;
int minute = 0;
int tenth = 0;
boolean run = false;

void setup() {
  lcd.init();
  lcd.backlight();
}


void loop() {
run = true;
tickClock();
}


void tickClock() {
 // Serial.println(millis() / 10);
  if (millis() - timer >= 100 || timer == 0) {
    tick();
    timer = millis();
  }
}

void tick() { // centang dilakukan setiap 100 milidetik, yaitu setiap sepersepuluh detik
  if (run) {
    updateLCD();
    if (tenth == 9) {
      tenth = 0;
      if (second == 59) {
        second = 0;
        minute++;
      } else {
        second++;
      }
    } else {
      tenth++;
    }
  }
}


void updateLCD() {
  lcd.setCursor(0, 0);
  if (minute < 10) {
    lcd.print("0");
  }
  lcd.print(minute, DEC);
  lcd.print(":");
  if (second < 10) {
    lcd.print("0");
  }
  lcd.print(second, DEC);
  lcd.print(":");
  lcd.print(tenth, DEC);
}
