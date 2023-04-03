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

using namespace std;


// #include "testplatform.h"

const double SCREEN_WIDTH = 700.0;
const double SCREEN_HEIGHT = 500.0;

class Game {
public:
   Game(Position ptUpperRight) : player(0.0, 0.0),
                                 ptUpperRight(ptUpperRight),
                                 time(0.0)
   {
      // Set the horizontal position of the player to the middle of the screen
      player.getPt().setX(ptUpperRight.getX() / 2.0);
   }

   Platform platforms[1] = {
       Platform(Position(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 7), SCREEN_WIDTH / 2, 40.0),
   };
    
   Player player;
   Position ptUpperRight;       // size of the screen
   double time;        // amount of time since began simulation (or last firing)
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

   // accept input
   bool justJumped;
   justJumped = pGame->player.userInput(pUI, pGame->platforms);
    
   // Update player position
   pGame->player.updateNewPosition(pGame->platforms, justJumped, SCREEN_WIDTH, SCREEN_HEIGHT);

   //
   // perform all the game logic
   //
    
   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGame->ptUpperRight.getY() - 20.0));
   gout.drawRectangle(pGame->platforms[0].bL, pGame->platforms[0].tR, 0.0, 250.0, 0.0);
    
   // draw the player
   gout.drawPlayer(pGame->player.getPt(), pGame->player.getOppositePoint());

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time elsapsed: "
        << pGame->time << "s\n";
    
   pGame->time += 0.03;
}


int main(int argc, const char * argv[]) {
    //Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setX(SCREEN_WIDTH);
    ptUpperRight.setY(SCREEN_HEIGHT);
    Interface ui(0, NULL,
    "Jump Man",   /* name on the window */
     ptUpperRight);
    
    // Initialize the game
    Game game(ptUpperRight);
    
    // Set everything into action
    ui.run(callBack, &game);
    
    return 0;
}
