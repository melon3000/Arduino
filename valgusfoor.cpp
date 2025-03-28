// Фиксация пинов для светодиодов
const int RED = 11;
const int YELLOW = 10;
const int GREEN = 9;
const int RED1 = 5;
const int GREEN1 = 6;

// Настройка времени для смены дневного и ночного режима
unsigned long lastChangeTime = 0;
unsigned long changeInterval = 20000;  // 20 секунд (можно изменить)
bool isNight = false;  // Начинаем с дневного режима

// Ночной режим
void nightMode() {
    // Желтый свет мигает
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED1, LOW);
    digitalWrite(GREEN1, LOW);
    delay(500);  // 500мс пауза для мигания желтого
    digitalWrite(YELLOW, LOW);
    delay(500);
}

// Дневной режим
void dayMode() {
    // Обычный цикл (авто и пешеходный светофор)
    
    // Красный для авто
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED1, LOW);
    digitalWrite(GREEN1, HIGH);  // Зеленый для пешеходов
    delay(5000);  // Красный 5 секунд

    // Желтый для авто
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    delay(3000);  // Желтый 3 секунды

    // Зеленый для авто
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED1, HIGH);  // Красный для пешеходов
    digitalWrite(GREEN1, LOW);  // Зеленый для пешеходов
    delay(5000);  // Зеленый авто 5 секунд

    // Мигающий зеленый
    for (int i = 0; i < 3; i++) {
        digitalWrite(GREEN, LOW);
        delay(200);
        digitalWrite(GREEN, HIGH);
        delay(200);
    }
    digitalWrite(GREEN, LOW);

    // Желтый на 1 секунду
    digitalWrite(YELLOW, HIGH);
    delay(1000);
    digitalWrite(YELLOW, LOW);
}

void setup() {
    // Настройка пинов как выходных
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(RED1, OUTPUT);
    pinMode(GREEN1, OUTPUT);

    // Начинаем с дневного режима
    isNight = false;
}

void loop() {
    unsigned long currentMillis = millis();
    
    // Если прошло больше 20 секунд, меняем режим
    if (currentMillis - lastChangeTime >= changeInterval) {
        isNight = !isNight; 
        lastChangeTime = currentMillis;  // Обновляем время последней смены режима
    }
    
    // Ночной режим
    if (isNight) {
        nightMode();  // Включаем ночной режим
    } else {
        dayMode();  // Включаем дневной режим
    }
}
