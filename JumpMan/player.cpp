//
//  player.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#include "player.h"
#include "physics.h"

Player::Player() : jumpStrength(4.5), lateralStrength(3.0), ptPlayer(0.0, 0.0), maxSpeed(20.0), terminalVelocity(-6.0), playerWidth(15) {}

Player::Player(double x, double y) : jumpStrength(4.5), lateralStrength(3.0), ptPlayer(x, y), maxSpeed(20.0), terminalVelocity(-6.0), playerWidth(15) {}

/**
 *   USER INPUT
 *   For now, have the player's movement respond immediately to
 *   player input (accel and velocity are the same)
 */
bool Player::userInput(const Interface * pUI, Platform platforms[]) {
    if (pUI->isRight() && pUI->isLeft())
        this->ddx = this->dx = 0.0;
    else if (pUI->isRight())
        this->ddx = this->dx = this->lateralStrength;
    else if (pUI->isLeft())
        this->ddx = this->dx = -this->lateralStrength;
    else
        this->ddx = this->dx = 0.0;
        
    
    // Return if jumped
    if (pUI->isSpace() && isStandingOnGround(&platforms)) {
        this->ddy = this->dy = this->jumpStrength;
        return true;
    }
    return false;
}

void Player::updateNewPosition(Platform platforms[], bool justJumped, double screenWidth, double screenHeight) {
    
    if (!isStandingOnGround(&platforms)) {
        ddy -= Physics::gravity*0.16;
        dy += ddy*0.16;
        if (dy < terminalVelocity)
            dy = terminalVelocity;
    } else if (justJumped) {
        dy += ddy*0.16;
    } else {
        ddy = dy = 0.0;
    }
    
    oldPtPlayer = Position(ptPlayer);
    
    double oldX = ptPlayer.getX();
    double oldY = ptPlayer.getY();
    
    ptPlayer.setX(oldX + dx);
    ptPlayer.setY(oldY + dy);
    
    playerBoundaryCorrections(oldPtPlayer, &platforms, screenWidth, screenHeight);
}

bool Player::isStandingOnGround(Platform * platforms[]) {
    
    int numPlatforms = sizeof(*platforms) / sizeof(platforms[0]);
    
    double playX = ptPlayer.getX();
    double playY = ptPlayer.getY();
    
    // Floor of game
    if (playY == 0.0)
        return true;
    
    // Check platforms
    for (int i = 0; i < numPlatforms; i++) {
        Platform & p = (*platforms)[i];
        
        if (p.floorY == playY
            && p.tL.getX() <= playX + playerWidth
            && p.tR.getX() >= playX)
            return true;
    }
    
    return false;
}


void Player::playerBoundaryCorrections(Position original, Platform * platforms[], double screenWidth, double screenHeight) {
    int numPlatforms = sizeof(*platforms) / sizeof(platforms[0]);
    
    std::cout << "Hello????\n";
    double oldX = original.getX();
    double oldY = original.getY();
    
    double newX = ptPlayer.getX();
    double newY = ptPlayer.getY();
    
    bool edgeOfMap = false;
    
    if (newX < 0.0) {
        ptPlayer.setX(0.0);
        resetHorizontalForces();
        edgeOfMap = true;
    }
    if (newX + playerWidth > screenWidth) {
        ptPlayer.setX(screenWidth - playerWidth);
        resetHorizontalForces();
        edgeOfMap = true;
    }

    // Standing on ground
    if (newY < 0.0) {
        ptPlayer.setY(0.0);
        resetVerticalForces();
        edgeOfMap = true;
    }
    // Hit ceiling
    if (newY + playerWidth > screenHeight) {
        ptPlayer.setY(screenHeight - playerWidth);
        resetVerticalForces();
        edgeOfMap = true;
    }
    
    if (edgeOfMap) return;
    
    // Platforms
    for (int i = 0; i < numPlatforms; i++) {
        Platform & pl = *platforms[i];
        if (!pl.isInside(ptPlayer, playerWidth)) continue;
        
        double rightX = pl.tR.getX();
        double leftX = pl.tL.getX();
        double topY = pl.tR.getY();
        double bottomY = pl.bR.getY();
        
        if /* Landed on platform */ (oldY >= topY) {
            ptPlayer.setY(topY);
            return resetVerticalForces();
        }
        
        if (oldY + playerWidth <= bottomY)/* Hit bottom of platform */ {
            ptPlayer.setY(bottomY - playerWidth);
            return resetVerticalForces();
        }
        
        if /* Left of platform */ (oldX + playerWidth <= leftX) {
            ptPlayer.setX(leftX - playerWidth);
            return resetHorizontalForces();
        }
        
        if /* Right of platform */ (oldX >= rightX) {
            ptPlayer.setX(rightX);
            return resetHorizontalForces();
        }
        
        throw "Uncaught case";
    }
}

void Player::resetVerticalForces() {
    dy = ddy = 0.0;
}

void Player::resetHorizontalForces() {
    dx = ddx = 0.0;
}

Position Player::getOppositePoint() {
    double x = ptPlayer.getX() + playerWidth;
    double y = ptPlayer.getY() + playerWidth;
    
    return Position(x, y);
}

