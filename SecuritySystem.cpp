
#include "SecuritySystem.h"
#include "PinConfig.h"

void SecuritySystem::begin() {
    pinMode(PIR_PIN, INPUT);
    pinMode(WINDOW_SENSOR_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(OUTDOOR_LED_PIN, OUTPUT);

    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(OUTDOOR_LED_PIN, LOW);

    motionDetected = false;
    windowOpen = false;
    alarmActive = false;

    Serial.println("Security System Ready");
}

void SecuritySystem::update(bool securityMode) {

    motionDetected = digitalRead(PIR_PIN) == HIGH;

    // LOW = Window Closed
    // HIGH = Window Open
    windowOpen = digitalRead(WINDOW_SENSOR_PIN) == HIGH;

    alarmActive = securityMode && windowOpen;

    digitalWrite(
        BUZZER_PIN,
        alarmActive ? HIGH : LOW
    );

    digitalWrite(
        OUTDOOR_LED_PIN,
        (securityMode && motionDetected) ? HIGH : LOW
    );
}

bool SecuritySystem::isAlarmActive() {
    return alarmActive;
}

bool SecuritySystem::isMotionDetected() {
    return motionDetected;
}

bool SecuritySystem::isWindowOpen() {
    return windowOpen;
}
