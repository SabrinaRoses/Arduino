#include <Arduino.h>

const int digitPins[4] = {10, 11, 12, 13};  // Pinos dos dígitos do display
const int segmentPins[8] = {2, 3, 4, 5, 7, 8, 9, 1};  // Pinos dos segmentos do display e do LED
const int ledPin = 1;  // Pino para o LED

const byte digitPatterns[10] = {
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B00111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110   // 9
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }

  pinMode(ledPin, OUTPUT);
}

void displayDigit(int digit, int digitPosition) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], HIGH);
  }

  byte pattern = digitPatterns[digit];

  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], !bitRead(pattern, i));
  }

  digitalWrite(digitPins[digitPosition], LOW);
}

void loop() {
  // Obtemos a hora atual
  int hours, hour, minutes, minute;

  // Acende o LED se as horas são pares
  digitalWrite(ledPin, hours % 2 == 0 ? HIGH : LOW);

  // Exibe as horas
  int digit1 = hours / 10;
  int digit2 = hours % 10;
  displayDigit(digit1, 0);
  delay(5);
  displayDigit(digit2, 1);
  delay(5);

  // Exibe os minutos
  int digit3 = minutes / 10;
  int digit4 = minutes % 10;
  displayDigit(digit3, 2);
  delay(5);
  displayDigit(digit4, 3);
  delay(5);
}
