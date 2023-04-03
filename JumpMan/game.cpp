//
//  game.cpp
//  JumpMan
//
//  Created by Samuel on 3/7/23.
//

#include <stdio.h>

#include <iostream>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "player.h"
#include "platform.h"
#include "door.h"
#include "key.h"

using namespace std;


// #include "testplatform.h"

const double SCREEN_WIDTH = 700.0;
const double SCREEN_HEIGHT = 500.0;

class Game {
public:
   Game(Position ptUpperRight) : door(SCREEN_WIDTH - 70.0, SCREEN_HEIGHT / 1.8 - 22.0),
                                 key(150.0, 224.0),
                                 player(0.0, 0.0),
                                 ptUpperRight(ptUpperRight),
                                 time(0.0)
   {
      // Set the horizontal position of the player to the middle of the screen
      player.getPt().setX(ptUpperRight.getX() / 2.0);
   }

   Platform platforms[4] = {
       Platform(Position(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 7), SCREEN_WIDTH / 2, 40.0),
       Platform(Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 225.0), 200.0, 20.0),
       Platform(Position(40.0, SCREEN_HEIGHT / 3), 200, 20.0),
       Platform(Position(SCREEN_WIDTH - 200.0, SCREEN_HEIGHT / 2.25), 200.0, 20.0),
   };
    
   int numPlatforms = sizeof(platforms) / sizeof(platforms[0]);
   
   Door door;
   Key key;
    
   Player player;
   Position ptUpperRight;       // size of the screen
   double time;        // amount of time since began simulation (or last firing)
   bool hasWon = false;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
    // The first step (like every single callback function in OpenGL) is to cast the void pointer into a game object.
    Game *pGame = (Game *)p;


    //
    // perform all the game logic
    //
     
    Position ptPlayer = pGame->player.getPt();
     
    if (pGame->key.touches(ptPlayer, pGame->player.getPlayerWidth()))
        pGame->key.openDoor(pGame->door);
     
    if (pGame->door.touches(ptPlayer, pGame->player.getPlayerWidth()) &&
        pGame->door.isOpen())
        pGame->hasWon = true;
     
    //
    // draw everything
    //

    ogstream gout(Position(10.0, pGame->ptUpperRight.getY() - 20.0));

    // Door
    auto [dR, dG, dB] = pGame->door.getColor();
    gout.drawRectangle(pGame->door.getBottomLeft(), pGame->door.getUpperRight(), dR, dG, dB);
     
    // Platforms
    for (int i = 0; i < pGame->numPlatforms; i++) {
        gout.drawRectangle(pGame->platforms[i].bL, pGame->platforms[i].tR, 0.0, 250.0, 0.0);
    }
     
    // Key
    auto [kR, kG, kB] = pGame->key.getColor();
    gout.drawRectangle(pGame->key.getBottomLeft(), pGame->key.getUpperRight(), kR, kG, kB);
     
    // Player
    gout.drawRectangle(ptPlayer, pGame->player.getOppositePoint(), 0.0, 0.0, 0.0);

    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    
    gout << "Time elapsed: "
         << pGame->time << "s    ";
    
    if (pGame->hasWon) {
        gout << "You won!";
        if (pUI->isSpace()) {
            exit(0);
        }
    } else {
        pGame->time += 0.03;
    }
        

    // accept input
    bool justJumped;
    justJumped = pGame->player.userInput(pUI, pGame->platforms, pGame->numPlatforms);

    // Update player position
    pGame->player.updateNewPosition(pGame->platforms, pGame->numPlatforms, justJumped, SCREEN_WIDTH, SCREEN_HEIGHT);
}


int main(int argc, const char * argv[]) {
    //Initialize OpenGL
    Position ptUpperRight(SCREEN_WIDTH, SCREEN_HEIGHT);
    Interface ui(0, NULL,
    "Jump Man",   /* name on the window */
     ptUpperRight);
    
    // Initialize the game
    Game game(ptUpperRight);
    
    // Set everything into action
    ui.run(callBack, &game);
    
    return 0;
}
