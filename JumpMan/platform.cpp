//
//  platform.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#include "platform.h"


Platform::Platform(Position bottomLeftPt, double length, double height) : floorY(bottomLeftPt.getY() + height) {
    bL = bottomLeftPt;
    bR = Position(bL.getX() + length, bL.getY());
    tL = Position(bL.getX(), bL.getY() + height);
    tR = Position(bL.getX() + length, bL.getY() + height);
}


bool Platform::isInside(Position & other, double playerWidth) {
    double x = other.getX();
    double y = other.getY();
    
    return (bL.getX() < x + playerWidth &&
            bR.getX() > x &&
            bL.getY() < y + playerWidth &&
            tR.getY() > y);
}
