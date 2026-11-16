
#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

#include <Arduino.h>

class SecuritySystem {
private:
    bool motionDetected;
    bool windowOpen;
    bool alarmActive;

public:
    void begin();

    void update(bool securityMode);

    bool isAlarmActive();
    bool isMotionDetected();
    bool isWindowOpen();
};

#endif
