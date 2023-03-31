#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
const int Start =6;
const int Stop =7;
int mulai=0;
int berhenti=0;

unsigned long timer = 0; //timer

int second = 0;
int minute = 0;
int milisecond = 0;

void setup() {
  pinMode(Start, INPUT);
  pinMode(Stop, INPUT);
  lcd.init();
  lcd.backlight();
}


void loop() {

if (digitalRead(Start) == HIGH) {
    mulai=1;
    berhenti=0;
  }

if (digitalRead(Stop) == HIGH) {
    mulai=0;
    berhenti=1;
  }
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
  if (mulai==1 && berhenti==0) {
    updateLCD();
    if (milisecond == 9) {
      milisecond = 0;
      if (second == 59) {
        second = 0;
        minute++;
      } else {
        second++;
      }
    } else {
      milisecond++;
    }
  } else  if (mulai==0 && berhenti==1) {
  minute=00;
  second=00;
  milisecond=00;
  delay(2000); //butuh delay untuk kirim data ke server (sebelum reset nilai variable)
  mulai=0;
  berhenti=0;
  updateLCD();
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
  lcd.print(milisecond, DEC);
}
