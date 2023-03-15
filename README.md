# JumpMan
A C++ OpenGL game in meant to simulate a typical platformer.

# MVP
## User Stories:
- The character shall be able to move left and right with the arrow keys.
- The character stops moving when
- The character shall jump and fall.
- The character shall land on obstacles.
- The character shall pick up the key, and the door will open.
- The character shall reach the exit, and the game will be complete.
- The user shall hit the space button at the end and the window will close.

## Requirements
- The character shall be able to move left and right with the arrow keys.
    - Allow the callback to listen to the events of left and
    - Have a stable acceleration
    - Add a maximum speed where the acceleration will immediately become ineffective.
    - Entities: Character, Physics, uiInteract
    - Collaborators: UIDraw, UIInteract, Platform

# Future features
