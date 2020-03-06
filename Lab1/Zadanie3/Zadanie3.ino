// Łukasz Szpak
// Środa 18:55
// Zadanie: 1.3 - Sterowanie LED z terminala

#define LED 6
#define CZAS_MIG 1000

unsigned long ostatniMig;
int czasMig;
bool mojStan;
bool czyMigam;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  czasMig = CZAS_MIG;
  czyMigam = false;
  mojStan = false;
  ostatniMig = millis();
}

void loop() {
  if (Serial.available() > 0) {
    String wiad = Serial.readStringUntil('\n');

    if (wiad.length() > 9) {
      String temp = wiad.substring(0, 9);
      czasMig = (wiad.substring(10)).toInt();
      wiad = temp;
    }

    if(wiad.equals("LED ON")) {
      digitalWrite(LED, HIGH);
      Serial.println("Wlaczylem LED !");
      czyMigam = false;
     
    } else if (wiad.equals("LED OFF")) {
      digitalWrite(LED, LOW);
      Serial.println("Wylaczylem LED !");
      czyMigam = false;
     
    } else if (wiad.equals("LED BLINK")) {
      czyMigam = true;
      Serial.println("Migam !");
     
    } else {
      Serial.println("ŹLE !");
     
    }

   
  }

  if (czyMigam) {
    unsigned long aktualnyCzas = millis();
   
    if ((aktualnyCzas - ostatniMig) > czasMig) {
      mojStan = !mojStan;
      digitalWrite(LED, mojStan);
      ostatniMig = aktualnyCzas;
    }
  }
}
