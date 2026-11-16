
#include "DoorSystem.h"
#include "SecuritySystem.h"

DoorSystem door;
SecuritySystem security;

void setup() {
    Serial.begin(9600);

    door.begin();
    security.begin();

    Serial.println("Smart Home Security System Started");
}

void loop() {
    door.update();

    security.update(
        door.isSecurityModeOn()
    );
}
