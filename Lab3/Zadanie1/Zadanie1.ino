// Łukasz Szpak
// Środa 18:55
// Zadanie: 4.1 - Miganie LED ze ściemniaczem

#define RED 6
#define GREEN 5
#define BUT1 8
#define BUT2 7
#define POT A0

#define DEF_TIME 1000

unsigned long long actTime;
unsigned long long lastSwitch;
bool whichColor;
int myTime;
int brightness; 


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(POT, INPUT);

  myTime = DEF_TIME;
  lastSwitch = 0;
  whichColor = true;
  brightness = 255;
}

void loop() {
  actTime = millis();
  brightness = (analogRead(POT) / 4);

  if (myTime != 0) {
    if (actTime - lastSwitch > myTime) {
      whichColor = !whichColor;

      lastSwitch = actTime;
    }
  }

  if (myTime < 0)
    myTime = 0;

  setLeds();
  checkButtons();
}

void setLeds() {
  if (whichColor) {
    analogWrite(GREEN, brightness);
    analogWrite(RED, 0);
  } else {
    analogWrite(RED, brightness);
    analogWrite(GREEN, 0);
  }
}

void checkButtons() {
  if (digitalRead(BUT1) == LOW) 
    myTime--;
  else if (digitalRead(BUT2) == LOW) 
    myTime++;
}
