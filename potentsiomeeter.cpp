int potPin = A0; // Пин потенциометра
int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);
  int mode = 0;

  // Выбор режима в зависимости от положения потенциометра
  if (potValue < 341) {
    mode = 0; // Режим 1 — Переливание
  } else if (potValue < 682) {
    mode = 1; // Режим 2 — Градиент
  } else {
    mode = 2; // Режим 3 — Бегущий огонь
  }

  if (mode == 0) {
    // Режим 1 — Переливание (R, G, B)
    for (int color = 0; color < 3; color++) {
      for (int i = 0; i < 10; i++) {
        if (i % 3 == color) {
          digitalWrite(ledPins[i], HIGH);
        } else {
          digitalWrite(ledPins[i], LOW);
        }
      }
      delay(300);
    }

  } else if (mode == 1) {
    // Режим 2 — Градиент (нарастание света)
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(150);
    }
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPins[i], LOW);
      delay(100);
    }

  } else if (mode == 2) {
    // Режим 3 — Бегущий огонь
    for (int i = 0; i < 10; i++) {
      // Сначала выключим все
      for (int j = 0; j < 10; j++) {
        digitalWrite(ledPins[j], LOW);
      }
      // Включим только один
      digitalWrite(ledPins[i], HIGH);
      delay(100);
    }
  }
}
