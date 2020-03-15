// Łukasz Szpak
// Środa 18:55
// Zadanie: 3.1 - Voltomierz LCD

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lastADC;
int myADC;
float voltage;
char line[16];
bool back;

define POT A0 
define BUTTON 8
define BACKLIGHT 6

void setup() {
  pinMode(POT, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BACKLIGHT, OUTPUT);
  
  lastADC = 0;
  myADC = 0;
  back = true;
  lcd.begin(16, 2);

  lcd.print("Miernik A0");
  Serial.begin(9600);
}

void loop() {
  myADC = analogRead(POT);
  
  if (myADC != lastADC) {
    voltage = myADC*5.00 / 1024.00;
    
    sprintf(line, "V=%.2f ADC=%d  ", voltage, myADC);
    
    lcd.setCursor(0, 1);
    lcd.print(line);

    lastADC = myADC;
  }

  
  
  if (digitalRead(BUTTON) == LOW) {
    delay(15);
    if (digitalRead(BUTTON) == LOW) {
      back = !back;
      digitalWrite(BACKLIGHT, back);
    }
  }
  
  delay(20);
}
