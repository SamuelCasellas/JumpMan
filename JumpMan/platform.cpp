//
//  platform.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#include "platform.h"


Platform::Platform(Position bottomLeftPt, double length, double height) {
    bL = bottomLeftPt;
    bR = Position(bL.getMetersX() * length, bL.getMetersY());
    tL = Position(bL.getMetersX(), bL.getMetersY() * height);
    tL = Position(bL.getMetersX() * length, bL.getMetersY() * height);
}
