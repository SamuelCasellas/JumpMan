//
//  platform.hpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#pragma once

#ifndef platform_h
#define platform_h

#include "player.h"
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
    
    bool touchingPlayer(Player * pl);
    
};

#endif /* platform_h */
