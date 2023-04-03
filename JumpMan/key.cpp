//
//  key.cpp
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#include "key.h"

Key::Key(double x, double y) : TangibleObject(x, y, 0.0, 0.0, 255.0) {
    setLength(5.0);
}

void Key::updateAppearance() {
    changeColor(255, 255, 255);
}

void Key::openDoor(Door &d) {
    d.openDoor();
    updateAppearance();
}
