#ifndef BRICK_H
#define BRICK_H
#include <iostream>
#include "util.h"
#include "food.h"
#include "ball.h"
using namespace std;
class Brick
{
private:
    int x;
    int y;
    int width;
    int height;
    Food obj;
    Ball **balls;
    char color;
    int collision;
    bool alive;
    int timer;
    static int bricks;
    static int score;
    int level;
    bool yellow;
    bool tStart;

public:
    Brick(int x = 0, int y = 0) : x(x), y(y), width(80), height(40), obj(-100, -100, 'w')
    {
        int random = rand() % 5;
        bricks++; // increases static int for store brick object count
        timer = 0;
        balls = new Ball *[2];
        tStart = false;
        alive = true;
        yellow = false;
        switch (random) // different collision counts for different ball colors
        {
        case 0:
            color = 'r';
            collision = 3;
            break;
        case 1:
            color = 'g';
            collision = 1;
            break;
        case 2:
            color = 'b';
            collision = 3;
            break;
        case 3:
            color = 'y';
            collision = 2;
            break;
        case 4:
            color = 'p';
            collision = 2;
            break;
        }
    }
    void setYellow(bool n) { yellow = n; }    // yellow setter
    static int getBricks() { return bricks; } // bricks getter
    void setBricks(int n) { bricks = n; }     // bricks setter
    bool getYellow() { return yellow; }       // yellow getter
    int getWidth() { return width; }          // width getter
    int getHeight() { return height; }        // height getter
    void setX(int n) { x = n; }               // x setter
    void setY(int n) { y = n; }               // y setter
    void setLevel(int n) { level = n; }       // level setter
    int getX() { return x; }                  // x getter
    int getY() { return y; }                  // y getter
    int getTimer() { return timer; }          // timer getter
    void setTimer(int n) { timer = n; }       // timer setter
    Ball **&getFoods() { return balls; }      // returns a reference to the double pointer ball object
    Food &getFood() { return obj; }           // return food object reference
    char getColor() { return color; }         // color getter
    void setColor(char c) { color = c; }      // color setter
    static int getScore() { return score; }   // score getter
    void startTimer() { tStart = true; }      // timer starter for food 5 second time
    void setTStart(bool n) { tStart = n; }    // timer setter
    virtual void draw()                       // brick drawer
    {
        if (alive) // if brick is alive, draw brick
        {
            if (color == 'g')
                DrawRoundRect(x, y, width, height, colors[DARK_SEA_GREEN], 10);
            else if (color == 'p')
                DrawRoundRect(x, y, width, height, colors[DEEP_PINK], 10);
            else if (color == 'b')
                DrawRoundRect(x, y, width, height, colors[DARK_BLUE], 10);
            else if (color == 'r')
                DrawRoundRect(x, y, width, height, colors[RED], 10);
            else if (color == 'y')
                DrawRoundRect(x, y, width, height, colors[GOLD], 10);
        }
        else // else draw the food that drops
        {
            obj.draw();
            if (level == 3) // if level is 3, there is a 50/50 chance of food going up or down
            {
                if (obj.getDirection() == 'd')
                    obj.setY(obj.getY() - 3);
                else
                    obj.setY(obj.getY() + 3);
            }
            else
                obj.setY(obj.getY() - 3);
        }
    }
    void incScore() { score += 5; } // score increaser
    void collide()                  // lowers collision by one
    {
        collision--;
        if (collision == 0) // if collisions are zero, remove the brick
        {
            alive = false;
            obj.setX(x);
            obj.setY(y);
            obj.setColor(color);
            x = -100;
            y = -100;
            incScore();
            bricks--;
        }
    }
    void setAlive(bool n) { alive = n; }  // status setter
    bool status() { return alive; }       // status getter
    void incTimer() { timer++; }          // timer increaser
    bool timerStatus() { return tStart; } // timer getter
};
int Brick::bricks = 0;
int Brick::score = 0;
#endif BRICK_H