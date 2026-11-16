
#ifndef DOOR_SYSTEM_H
#define DOOR_SYSTEM_H

#include <Arduino.h>
#include <Servo.h>
#include <Keypad.h>

class DoorSystem {
private:
    Servo doorServo;
    Keypad* keypad;

    String password;
    String enteredPassword;

    bool doorOpen;
    bool securityMode;

    unsigned long openTime;

public:
    DoorSystem();

    void begin();
    void update();

    bool isDoorOpen();
    bool isSecurityModeOn();
};

#endif
