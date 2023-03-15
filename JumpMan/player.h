//
//  character.hpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include "position.h"
#include "uiInteract.h"

class Player {
    const double jumpStrength; // the vertical thrust of the player's jump
    const double lateralStrength;
public:
    Player(/* Starting position for ptPlayer */
           double x, double y);
    
    Position getPt()const { return ptPlayer; }
    
    void userInput(const Interface * pUI);
    
    // methods
    void calculateNewPosition();
    
    // For supporting the draw rectangle method in uiDraw
    Position getOffsetPoint();
private:
    Position ptPlayer;
    
    double aRadians;            // Angle in radians
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double dx;
    double dy;
    double v;                   // Total velocity
};

#endif /* player_h */
