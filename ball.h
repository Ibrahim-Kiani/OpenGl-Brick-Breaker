#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "util.h"
using namespace std;
class Ball
{
private:
    int x;
    int y;
    int velocity;
    char color;
    char direction;
    bool alive;
    const int size = 10;
    static int balls;

public:
    Ball(int x = 450, int y = 150) : x(x), y(150), velocity(4), color('b'), direction('e'), alive(1)
    {
        balls++; // increases the static int that stores number of ball objects
    }
    ~Ball()
    {
        balls--; // decreases the static int that stores number of ball objects
    }
    int getBalls() { return balls; }             // ball getter
    void setX(int n) { x = n; }                  // x setter
    void setY(int n) { y = n; }                  // y setter
    void setDirection(char c) { direction = c; } // direction setter
    char getDirection() { return direction; }    // direction getter
    bool getAlive() { return alive; }            // status getter
    void setAlive(bool n) { alive = n; }         // status setter
    int getX() { return x; }                     // x getter
    int getY() { return y; }                     // y getter
    char getColor() { return color; }            // color getter
    void setColor(char c) { color = c; }         // color setter
    void incVelocity()                           // velocity increaser
    {
        if (velocity <= 10) // max velocity is 10
            velocity += 2;
    }
    void decVelocity() // velocity decreaser
    {
        if (velocity >= 4) // lowest velocity is 4
            velocity -= 2;
    }

    void rightX() { x += velocity; }   // moves ball right
    void leftX() { x -= velocity; }    // moves ball left
    void upY() { y += velocity; }      // moves ball up
    void downY() { y -= velocity; }    // moves ball down
    Ball &instance() { return *this; } // returns the instance of the object
    Ball(Ball &obj)                    // copy constructor
    {
        x = obj.x;
        y = obj.y;
        velocity = obj.velocity;
        color = obj.color;
        direction = obj.direction;
        balls++;
    }
    virtual void collisionCheck()
    {
        cout << "polymorphism :)\n";
    }
    void move() // moves the ball
    {
        switch (direction)
        {
        case 'e':
            rightX();
            upY();
            break;
        case 'q':
            leftX();
            upY();
            break;
        case 'z':
            leftX();
            downY();
            break;
        case 'c':
            rightX();
            downY();
            break;
        }
    }
    void draw() // draws the ball
    {
        if (color == 'g')
            DrawCircle(x, y, size, colors[GREEN]);
        else if (color == 'p')
            DrawCircle(x, y, size, colors[DEEP_PINK]);
        else if (color == 'b')
            DrawCircle(x, y, size, colors[BLUE]);
        else if (color == 'r')
            DrawCircle(x, y, size, colors[RED]);
        else if (color == 'y')
            DrawCircle(x, y, size, colors[GOLD]);
    }
};
int Ball::balls = 0;
#endif BALL_H