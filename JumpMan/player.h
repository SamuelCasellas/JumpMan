//
//  player.h
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include "position.h"
#include "platform.h"
#include "uiInteract.h"

class Player {
    // friend TestPlayer;
    double jumpStrength; // the vertical thrust of the player's jump
    double lateralStrength; // Acceleration from running
    double maxSpeed;
    double terminalVelocity;
public:
    Player();
    Player(double x, double y);
    
    Position getPt()const { return ptPlayer; }
    
    bool userInput(const Interface * pUI, Platform platforms[], int numPlatforms);
    
    void updateNewPosition(Platform platforms[], int numPlatforms, bool justJumped, double screenWidth, double screenHeight);
    
    // For supporting the draw rectangle method in uiDraw
    Position getOppositePoint();
    
    int getPlayerWidth() { return playerWidth; }
private:
    Position ptPlayer;
    Position oldPtPlayer;
    
    const int playerWidth;
    
    bool isStandingOnGround(Platform platforms[], int numPlatforms);
    void playerBoundaryCorrections(Position original, Platform platforms[], int numPlatforms, double screenWidth, double screenHeight);
    
    void resetVerticalForces();
    void resetHorizontalForces();
    
    double aRadians;            // Angle in radians
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double dx;
    double dy;
    double v;                   // Total velocity
};

#endif /* player_h */
