#ifndef PADDLE_H
#define PADDLE_H
#include <iostream>
#include "util.h"
using namespace std;
class Paddle
{
private:
    int size;
    int x;
    int y;
    char color;

public:
    Paddle() // constructor
    {
        x = 450;
        size = 200;
        y = 50;
        color = 'w';
    }
    Paddle(Paddle &obj) // copy constructor
    {
        x = obj.x;
        y = obj.y;
        color = obj.color;
        size = obj.size;
    }
    void setColor(char c) { color = c; } // color setter
    char getColor() { return color; }    // color getter
    Paddle &instance() { return *this; } // returns the instance of the object
    int getX() { return x; }             // x getter
    int getY() { return y; }             // y getter
    int getSize() { return size; }       // size getter
    void setSize(int n) { size = n; }    // size setter
    void setX(int n) { x = n; }          // x setter
    void setY(int n) { y = n; }          // y setter
    void draw()                          // draw function for paddle
    {
        if (color == 'g')
            DrawRectangle(x, y, size, 30, colors[DARK_SEA_GREEN]);
        else if (color == 'p')
            DrawRectangle(x, y, size, 30, colors[DEEP_PINK]);
        else if (color == 'b')
            DrawRectangle(x, y, size, 30, colors[DARK_BLUE]);
        else if (color == 'r')
            DrawRectangle(x, y, size, 30, colors[RED]);
        else if (color == 'y')
            DrawRectangle(x, y, size, 30, colors[GOLD]);
        else
            DrawRectangle(x, y, size, 30, colors[BLACK]);
    }
};
#endif PADDLE_H