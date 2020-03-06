// Łukasz Szpak
// Środa 18:55
// Zadanie: 1.1 - Licznik na dwa przyciski

#define PRZYCISK_1 4
#define PRZYCISK_2 2
#define LED 6
#define DELAY_BLINKANIA 50

int licznik;
bool czy;

void setup() {
  licznik = 0;
 
  Serial.begin(9600);

  pinMode(PRZYCISK_1, INPUT_PULLUP);
  pinMode(PRZYCISK_2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  delay(150);
}

void loop() {
  czy = false;
 
  if (czyWcisniety1() && czyWcisniety2()) {
    while (czyWcisniety1() && czyWcisniety2());
    blinkanie();
     
  } else if (czyWcisniety1()) {
    while (czyWcisniety1()) {
      if(czyWcisniety2()) {
        while (czyWcisniety2());
        blinkanie();
        czy = true;
      }
    }
    if(!czy) {
      licznik++;
      Serial.println("Wcisnieto: ");
      Serial.println(licznik);
    }
   
   
  } else if (czyWcisniety2()) {
    while (czyWcisniety2()) {
      if (czyWcisniety1()) {
        while (czyWcisniety1());
        blinkanie();
        czy = true;
      }
    }
    if(!czy) {
      licznik--;
      Serial.println("Wcisnieto: ");
      Serial.println(licznik);
    }
   
  }

}

bool czyWcisniety1(void) {
  if(digitalRead(PRZYCISK_1) == LOW) {
    delay(5);
    if(digitalRead(PRZYCISK_1) == LOW)
      return true;
    else
      return false;
  }
  return false;
}

bool czyWcisniety2(void) {
  if(digitalRead(PRZYCISK_2) == LOW) {
    delay(5);
    if(digitalRead(PRZYCISK_2) == LOW)
      return true;
    else
      return false;
  }
  return false;
}

void blinkajLedem(void) {
  digitalWrite(LED, HIGH);
  delay(DELAY_BLINKANIA);
  digitalWrite(LED, LOW);
  delay(DELAY_BLINKANIA);
}

void blinkanie() {
  Serial.println("Wcisnales oba na raz - blinkam ledem");
    for (int i = 0; i < licznik; i++)
      blinkajLedem();
}
