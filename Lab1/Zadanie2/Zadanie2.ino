// Łukasz Szpak
// Środa 18:55
// Zadanie: 1.2 - Czas wciśnięcia przycisku

#define PRZYCISK 10

void setup() {
  Serial.begin(9600);

  pinMode(PRZYCISK, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(PRZYCISK) == LOW) {
    delay(20);

    if (digitalRead(PRZYCISK) == LOW) {
      unsigned long czasNacisniecia = millis();

      while (digitalRead(PRZYCISK) == LOW) {
        //czekamy az Szanowny uzytkownik pusci przycisk
      }
      unsigned long czasTrzymania = millis() - czasNacisniecia;
      Serial.print("Przycisk wcisniety przez: ");
      Serial.print(czasTrzymania);
      Serial.print(" -> ");
      Serial.print((int)(czasTrzymania / 3600000));
      czasTrzymania %= 3600000;
      Serial.print(":");
      Serial.print((int)(czasTrzymania / 60000));
      czasTrzymania %= 60000;
      Serial.print(":");
      Serial.print((int)(czasTrzymania / 1000));
      czasTrzymania %= 1000;
      Serial.print(".");
      Serial.println(czasTrzymania);
    }
    
  }

}
