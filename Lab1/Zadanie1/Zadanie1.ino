// Łukasz Szpak
// Środa 18:55
// Zadanie: 1.1 - Licznik na dwa przyciski

#define PRZYCISK_1 10
#define PRZYCISK_2 10
#define LED 10

#define DELAY_BLINKANIA 50

int licznik;

void setup() {
  licznik = 0;
  
  Serial.begin(9600);

  pinMode(PRZYCISK_1, INPUT_PULLUP);
  pinMode(PRZYCISK_2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

}

void loop() {
  if (czyWcisniety1() && czyWcisniety2()) {
    Serial.println("Wcisnales oba na raz - blinkam ledem");
    for (int i = 0; i < licznik; i++)
      blinkajLedem();
      
  } else if (czyWcisniety1()) {
    licznik++;
    Serial.println("Wcisnieto: ");
    Serial.println(licznik);
    
  } else if (czyWcisniety2()) {
    licznik--;
    Serial.println("Wcisnieto: ");
    Serial.println(licznik);
  }

}

bool czyWcisniety1(void) {
  if(digitalRead(PRZYCISK_1) == LOW) {
    delay(20);
    if(digitalRead(PRZYCISK_1) == LOW)
      return true;
    else
      return false;
  }
  return false;
}

bool czyWcisniety2(void) {
  if(digitalRead(PRZYCISK_2) == LOW) {
    delay(20);
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
