#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "util.h"
class Menu
{
private:
    int **coordinates;
    bool onScreen;

public:
    Menu()
    {
        onScreen = true;
        coordinates = new int *[3]; // 3 pairs of xy coordinates
        for (int i = 0; i < 3; i++)
            coordinates[i] = new int[2];
        int n = 0;
        for (int i = 0; i < 3; i++) // for different y coordinates
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                    coordinates[i][j] = 300;
                else
                    coordinates[i][j] = 200 + n;
            }
            n += 200;
        }
    }
    void draw() // draw menu
    {
        DrawString(100, 800, "PRESS NUM KEY TO PICK LEVEL");
        for (int i = 0; i < 3; i++)
        {
            DrawRectangle(coordinates[i][0], coordinates[i][1], 400, 100, colors[BLACK]);
            if (i == 0)
                DrawString(coordinates[i][0] + 150, coordinates[i][1] + 50, "LEVEL 1", colors[LIGHT_BLUE]);
            else if (i == 1)
                DrawString(coordinates[i][0] + 150, coordinates[i][1] + 50, "LEVEL 2", colors[LIGHT_GOLDEN_ROD_YELLOW]);
            else if (i == 2)
                DrawString(coordinates[i][0] + 150, coordinates[i][1] + 50, "LEVEL 3", colors[RED]);
        }
    }
    int **getCoordinates() { return coordinates; } // return coordinates
    bool getOnscreen() { return onScreen; } // return bool
    void setOnscreen(bool n) { onScreen = n; } // set bool
};
#endif MENU_H