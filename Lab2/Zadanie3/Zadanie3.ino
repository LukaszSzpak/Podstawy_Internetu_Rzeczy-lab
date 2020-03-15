// Łukasz Szpak
// Środa 18:55
// Zadanie: 3.3 - Logger UART do LCD

#include <LiquidCrystal.h>

#define ARRSIZE 15
#define BUTUP 9
#define BUTDOWN 8
#define ROLLDELAY 250

String mesArr[ARRSIZE];
int actSize;
int actPos;
bool refresh;

int mesPos[2];
long long lastUpdate;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  pinMode(BUTUP, INPUT_PULLUP);
  pinMode(BUTDOWN, INPUT_PULLUP);
  
  actSize = 0;
  actPos = 0;
  refresh = false;
  lastUpdate = 0;
  
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String newMes = Serial.readStringUntil('\n');
    checkSizeAndAdd(newMes);   
  }

  if (refresh) {
    refresh = false;
    
    lcd.clear();
    printDataOnLcd();
  }

  checkButtons();
  checkPos();

  delay(20);
}

void checkSizeAndAdd(String newString) {
  if (actSize >= ARRSIZE) {
    for (int i = 0; i < ARRSIZE - 1; i++) {
      mesArr[i] = mesArr[i+1];
    }
    mesArr[ARRSIZE-1] = newString;
  } else {
    mesArr[actSize] = newString;
    actSize++;
  }
  refresh = true;
  actPos = actSize;

  mesPos[0] = 0;
  mesPos[1] = 0;
  lastUpdate = millis();
}

void printDataOnLcd() {
  if (actSize == 1) {
    lcd.setCursor(0, 0);
    lcd.print(mesArr[0].substring(mesPos[0]));
  } else {
    lcd.setCursor(0, 0);
    lcd.print(mesArr[actPos - 2].substring(mesPos[0]));
    lcd.setCursor(0, 1);
    lcd.print(mesArr[actPos - 1].substring(mesPos[1]));
  }
}

void checkButtons() {
  if (digitalRead(BUTUP) == LOW) {
    delay(5);
    if (digitalRead(BUTUP) == LOW) {
      while (digitalRead(BUTUP) == LOW);
      actPos++;
      if (actPos > actSize)
        actPos = 2;
      refresh = true;
      mesPos[0] = 0;
      mesPos[1] = 0;
    }   
  }

  if (digitalRead(BUTDOWN) == LOW) {
    delay(5);
    if (digitalRead(BUTDOWN) == LOW) {
      while (digitalRead(BUTDOWN) == LOW);
      actPos--;
      
      if (actPos < 2) {
        actPos = actSize;
      }
      refresh = true;
      mesPos[0] = 0;
      mesPos[1] = 0;
    }   
  }
}

void checkPos() {
  if (millis() - lastUpdate > ROLLDELAY) {
    if (actSize == 0) {
      
    } else if (actSize == 1) {
      if (mesArr[0].length() > 16) {
        mesPos[0] = mesPos[0] + 1;
        if (mesArr[0].length() - mesPos[0] < 16)
          mesPos[0] = 0;
        refresh = true;
      }
    } else {
      if (mesArr[actPos - 2].length() > 16) {
        mesPos[0] = mesPos[0] + 1;
        if (mesArr[actPos - 2].length() - mesPos[0] < 16)
          mesPos[0] = 0;
        refresh = true;
      }
      if (mesArr[actPos - 1].length() > 16) {
        mesPos[1] = mesPos[1] + 1;
        if (mesArr[actPos - 1].length() - mesPos[1] < 16)
          mesPos[1] = 0;
        refresh = true;
      }
    }

    lastUpdate = millis();
  }
}
