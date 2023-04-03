//
//  platform.h
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#pragma once

#ifndef platform_h
#define platform_h

#include "position.h"

#include <stdio.h>

/***********************************************
 *   PLATFORM
 *   Currently limited to rectangles for easy detection of contact with player.
 *
 ************************************************************************/
class Platform {
public:
    Platform(Position bottomLeftPt, double length, double height);
    
    // The four corners of the rectangle
    Position tL;
    Position tR;
    Position bL;
    Position bR;
    
    const double floorY;
    
    bool isInside(Position & other, double playerWidth=0.0);
    
};

#endif /* platform_h */
