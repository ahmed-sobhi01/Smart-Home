
#include "DoorSystem.h"
#include "PinConfig.h"

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

Keypad doorKeypad = Keypad(
    makeKeymap(keys),
    rowPins,
    colPins,
    ROWS,
    COLS
);

DoorSystem::DoorSystem() {
    password = "1234";
    enteredPassword = "";
    doorOpen = false;
    securityMode = false;
    openTime = 0;
    keypad = nullptr;
}

void DoorSystem::begin() {
    doorServo.attach(SERVO_PIN);
    doorServo.write(0);

    Serial.println("Door System Ready");
    Serial.println("Enter Password:");
}

void DoorSystem::update() {
    char key = doorKeypad.getKey();

    if (key) {
        if (key == '*') {
            enteredPassword = "";
            Serial.println("Password Cleared");
        }
        else if (key == '#') {
            if (enteredPassword == password) {
                Serial.println("Access Granted");
                doorServo.write(90);
                doorOpen = true;
                openTime = millis();
            }
            else {
                Serial.println("Access Denied");
            }

            enteredPassword = "";
        }
        else if (key >= '0' && key <= '9') {
            enteredPassword += key;
            Serial.println("Key Pressed");
        }
        else if (key == 'A') {
            securityMode = !securityMode;

            Serial.print("Security Mode: ");
            Serial.println(securityMode ? "ON" : "OFF");
        }
    }

    if (doorOpen && millis() - openTime >= 5000) {
        doorServo.write(0);
        doorOpen = false;
        Serial.println("Door Closed");
    }
}

bool DoorSystem::isDoorOpen() {
    return doorOpen;
}

bool DoorSystem::isSecurityModeOn() {
    return securityMode;
}
