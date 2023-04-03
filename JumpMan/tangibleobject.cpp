//
//  tangibleobject.cpp
//  JumpMan
//
//  Created by Samuel on 4/3/23.
//

#include "tangibleobject.h"

TangibleObject::TangibleObject(double x, double y) : objectsColors(0.0, 0.0, 0.0) {
    ptObj = Position(x, y);
}

TangibleObject::TangibleObject(double x, double y, double r, double g, double b) : objectsColors(r, g, b) {
    ptObj = Position(x, y);
}

bool TangibleObject::touches(const Position &other, double offset) {
    
    double otherX = other.getX();
    double otherY = other.getY();
    
    double objX = ptObj.getX();
    double objY = ptObj.getY();

    return (otherX <= objX && otherX + offset >= objX
            && otherY <= objY && otherY + offset >= objY);

}

const Position TangibleObject::getBottomLeft() {
    return Position(ptObj.getX() - (length / 2.0), ptObj.getY() - (length / 2.0));
}

const Position TangibleObject::getUpperRight() {
    return Position(ptObj.getX() + (length / 2.0), ptObj.getY() + (length / 2.0));
}

void TangibleObject::changeColor(double r, double g, double b) {
    auto updatedTuple = std::tuple<double, double, double>{ r, g, b };
    objectsColors = updatedTuple;
}
