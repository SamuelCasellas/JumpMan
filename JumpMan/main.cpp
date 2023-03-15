//
//  main.cpp
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

class Game {
public:
   Game(Position ptUpperRight) : player(0.0, 0.0),
                                 ptUpperRight(ptUpperRight),
                                 time(0.0)
   {
      // Set the horizontal position of the player to the middle of the screen
      player.getPt().setMetersX(Position(ptUpperRight).getMetersX() / 2.0);

      // Generate the ground and set the vertical position of the howitzer.
      // ground.reset(howitzer.ptHowitzer);
   }

   Platform platforms[1] = {
       Platform(Position(20.0, 50.0), 50.0, 10.0),
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
   // The first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Game *pGame = (Game *)p;

   //
   // accept input
   //

   pGame->player.userInput(pUI);

   //
   // perform all the game logic
   //

   // advance time (assuming 60 frames per sec).
    pGame->time += 0.01666;
    
   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGame->ptUpperRight.getPixelsY() - 20.0));
   gout.drawRectangle(pGame->platforms[0].bL, pGame->platforms[0].tR, 0.0, 250.0, 0.0);
    
   // draw the player
   gout.drawPlayer(pGame->player.getPt(), pGame->player.getOffsetPoint());

   // draw some text on the screen
   gout.setf(std::ios::fixed | std::ios::showpoint);
   gout.precision(1);
   gout << "Time elsapsed: "
        << pGame->time << "s\n";
}


int main(int argc, const char * argv[]) {
    //Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);
    Position().setZoom(0.1 /* 0.1 meters equals 1 pixel */);
    Interface ui(0, NULL,
    "Game",   /* name on the window */
     ptUpperRight);
    
    //Initialize the game
    Game game(ptUpperRight);
    
    //set everything into action
    ui.run(callBack, &game);
    
    return 0;
}
