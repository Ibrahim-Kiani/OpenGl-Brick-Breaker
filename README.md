# OpenGL Brick Breaker Game

A classic Brick Breaker game implemented in C++ using OpenGL and GLUT libraries. Break all the bricks with a bouncing ball to win!

## Features

- Three different game levels with increasing difficulty
- Colorful bricks with different hit points
- Power-ups that affect gameplay:
  - Green: Increases paddle size
  - Red: Increases ball speed temporarily
  - Blue: Decreases ball speed temporarily
- Score tracking and high score system
- Lives system
- Interactive menu

## Controls

- **Mouse Movement**: Control the main paddle
- **A/D Keys**: Control the upper paddle in Level 3
- **1/2/3 Keys**: Select game level from the menu
- **Mouse**: Move the paddle to bounce the ball

## Game Mechanics

- Break all bricks to win the level
- Each brick has a different number of hit points based on its color
- If the ball falls below the paddle, you lose a life
- Game ends when all lives are lost
- Special diamond pattern in Level 3 with dual paddle control

## Prerequisites

To compile and run this game, you need:

- C++ compiler (GCC or Visual C++)
- OpenGL library
- GLUT (OpenGL Utility Toolkit)
- CImg library (included)

## Building and Running

### Windows with MinGW

1. Install MinGW with the necessary OpenGL and GLUT packages
2. Open Command Prompt in the project directory
3. Compile the game:
   ```
   g++ game.cpp -o BrickBreaker -lglut32 -lopengl32 -lglu32
   ```
4. Run the game:
   ```
   BrickBreaker.exe
   ```

### Windows with Visual Studio

1. Create a new Visual C++ project
2. Add all the source files to the project
3. Configure the project to link with OpenGL and GLUT libraries
4. Build and run the project

### Linux

1. Install the required packages:
   ```
   sudo apt-get install freeglut3-dev
   ```
2. Compile the game:
   ```
   g++ game.cpp -o BrickBreaker -lglut -lGL -lGLU
   ```
3. Run the game:
   ```
   ./BrickBreaker
   ```

## Project Structure

- `game.cpp`: Main game file containing the game loop and OpenGL setup
- `ball.h`: Ball class implementation
- `brick.h`: Brick class implementation
- `food.h`: Power-up implementation
- `level.h`: Level management and game logic
- `menu.h`: Game menu implementation
- `paddle.h`: Paddle class implementation
- `util.h`: Utility functions for drawing and other operations

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- OpenGL and GLUT for providing the graphics framework
- Sibt ul Hussain for the utility functions in util.h
