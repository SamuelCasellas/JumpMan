//
//  character.cpp
//  Wall_Jumper
//
//  Created by Samuel on 3/14/23.
//

#include "player.h"

Player::Player(double x, double y): jumpStrength(10.0), lateralStrength(10.0), ptPlayer(x, y) {}

void Player::userInput(const Interface * pUI) {
    if (pUI->isRight() && pUI->isLeft())
        this->ddx = 0.0;
    else if (pUI->isRight())
        this->ddx = this->lateralStrength;
    else if (pUI->isLeft())
        this->ddx = -this->lateralStrength;
    
    if (pUI->isSpace())
        this->ddy = this->jumpStrength;
}

Position Player::getOffsetPoint() {
    double x = this->ptPlayer.getMetersX() + 5;
    double y = this->ptPlayer.getMetersY() + 5;
    
    return Position(x, y);
}

