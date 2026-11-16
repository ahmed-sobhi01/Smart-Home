
#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include <Arduino.h>

// Door Access System
#define SERVO_PIN 9

#define ROWS 4
#define COLS 4

const byte rowPins[ROWS] = {2, 3, 4, 5};
const byte colPins[COLS] = {6, 7, 8, 10};

// Security System
#define PIR_PIN 11
#define WINDOW_SENSOR_PIN 12
#define BUZZER_PIN 13
#define OUTDOOR_LED_PIN A0

#endif
