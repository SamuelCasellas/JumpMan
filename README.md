# Author
Samuel Casellas

# JumpMan
A C++ OpenGL game in meant to simulate a typical platformer.

# Noun Identification Process
1. Generate Use-Cases
2. Pick a Use-Case
3. Generate Requirements
4. Pick One Requirement
5. Identify Entities
6. Identify Collaborators

# MVP

## Use Case:
- ~~The character shall be able to move left and right with the arrow keys.~~
- ~~The character stops moving immediately laterally when no keys are pressed.~~
- ~~The character shall jump and fall.~~
- ~~The character shall land on platforms.~~
- The character shall pick up a key to open a door.
- The character shall reach the exit, and the game will be complete.
- The user shall hit the space button at the end and the window will close.

## Requirements
- The character shall be able to move left and right with the arrow keys.
    * ~~Allow the callback to listen to the events of left and right arrow presses~~
    * ~~Have a stable velocity~~
    -> Entities: Player, Physics, uiInteract
    -> Collaborators: UIDraw, UIInteract, Platform

- The character shall jump and fall.
    * ~~Include a terminal velocity as an attribute to the player~~
    * ~~Make a method to see if the player is standing on the ground. If so, immediately set vertical velocity to 0.~~
    * ~~Mark the initial velocity (and accel) to the thrust of the player's jump~~
    * ~~Subtract gravity to accel~~

- The character shall pick up a key to open a door.
    * ~~Make a base class for TangibleObject~~
    * ~~TangibleObject shall have a touches method for the other object to know when in contact~~
    * ~~TangibleObject shall have a changeColor method to update the color of object.~~
    * ~~Derive two classes from this base class: Key and Door.~~
    * ~~Key class shall have dependency to door with openDoor method~~

- The character shall reach the exit, and the game will be complete.
    * 
- The user shall hit the space button at the end and the window will close.
    * Detect when the space bar is pressed when the game is in a completed state.
# Future features
    * Adding a more robust set of physics for lateral movement by implementing its own accel
    * Generating graphics for the player to be a character rather than a square
    * Creating enemies to avoid
    * Adding more levels
    * Adding sounds and music
