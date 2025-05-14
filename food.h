#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "util.h"
class Food
{
private:
    int x;
    int y;
    bool alive;
    char direction;
    char color;

public:
    Food(int x = 0, int y = 0, char c = 0) : x(x), y(y), alive(1), color(c) // constructor
    {
        int n = rand() % 2; // for level 3 possibility
        if (n)
            direction = 'u';
        else
            direction = 'd';
    }
    void setColor(char c) { color = c; }         // color setter
    char getColor() { return color; }            // color getter
    void setX(int n) { x = n; }                  // x setter
    char getDirection() { return direction; }    // direction getter
    void setDirection(char n) { direction = n; } // direction setter
    void setY(int n) { y = n; }                  // y setter
    bool status() { return alive; }              // status getter
    void collide()                               // collision with paddle condition
    {
        alive = false; // removes foods
        x = -100;      // teleports them away from screen
        y = -100;
        color = 'w';
    }
    int getX() { return x; } // x getter
    int getY() { return y; } // y getter
    void draw()              // food draw function
    {
        if (color == 'g')
        {
            DrawTriangle(x - 20, y - 20, x, y + 10, x + 20, y - 20, colors[GREEN]);
        }
        else if (color == 'b')
        {
            DrawCircle(x, y, 20, colors[DARK_BLUE]);
        }
        else if (color == 'r')
        {
            DrawRectangle(x, y, 60, 30, colors[RED]);
        }
        else if (color == 'p')
        {
            DrawSquare(x, y, 30, colors[DEEP_PINK]);
        }
        else if (color == 'y')
        {
            DrawSquare(x, y, 30, colors[GOLD]);
        }
    }
};
#endif FOOD_H