//
//  door.cpp
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#include "door.h"

Door::Door(double x, double y) : TangibleObject(x, y, 0.0, 0.0, 0.0) {
    setLength(30.0);
}

void Door::openDoor() {
    open = true;
    updateAppearance();
}

void Door::updateAppearance() {
    changeColor(0.0, 0.0, 250.0);
}
