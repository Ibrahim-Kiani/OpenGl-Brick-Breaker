#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include "util.h"
#include <fstream>
#include "menu.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "food.h"
using namespace std;
class Level : public Paddle, public Ball, public Menu, public Brick
{
private:
    int level;
    int lives;
    int rows;
    int col;
    int timer;
    int highscore;
    Brick **array;
    Paddle *l3;
    bool over;
    void init(int i = 0, int j = 0)
    {
        if (j >= col)
        {
            i++;
            j = 0;
        }
        if (j == 0)
        {
            array[i] = new Brick[col];
        }
        if (i >= rows)
            return;
        array[i][j].setLevel(level);
        if (level == 1)
        {
            array[i][j].setX(100 + j * array[i][j].getWidth());
            array[i][j].setY(100 + i * array[i][j].getHeight());
        }
        else
        {
            array[i][j].setX(100 + j * array[i][j].getWidth());
            array[i][j].setY(200 + i * array[i][j].getHeight());
        }
        init(i, j + 1);
    }

    void helper(int i, int j, int k) // helper of recursive function
    {
        if (j > k)
            return;
        array[i][j].setAlive(0);
        helper(i, j + 1, k);
    }
    void diamondPattern(int i = 1, int k = 0) // recursive function
    {
        if (i >= rows)
            return;
        if (i < rows / 2)
        {
            helper(i, rows / 2 - i, rows / 2 + k - 1);
            diamondPattern(i + 1, k + 1);
        }
        else
        {
            helper(i, rows / 2 - k, rows / 2 + k - 2);
            diamondPattern(i + 1, k - 1);
        }
    }

public:
    Level(int l = 1) : level(l), lives(2)
    {
        srand(time(0));
        over = false;
        timer = 0;
        if (l == 1) // intializes first level
        {
            rows = 5, col = 10;
            array = new Brick *[rows];
            init();
        }
        else if (l == 2) // intializes second level
        {
            rows = 15;
            col = 3;
            array = new Brick *[rows];
            for (int i = 0; i < rows; i++)
            {
                array[i] = new Brick[col];
            }
            int w = 0, h = 0;
            for (int i = 0; i < 5; i++) // loop for drawing pattern for second level
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        array[i * 3 + j][k].setLevel(level);
                        array[i * 3 + j][k].setX(w + 150 + j * array[j][k].getWidth());
                        array[i * 3 + j][k].setY(h + 80 + k * array[j][k].getHeight());
                    }
                }
                if (i < 2)
                {
                    w += 3 * (**array).getWidth();
                    h += 3 * (**array).getHeight();
                }
                else
                {
                    w -= 3 * (**array).getWidth();
                    h += 3 * (**array).getHeight();
                }
            }
            Ball::setX(800);
        }
        else if (l == 3) // intializes third level
        {
            rows = 12, col = 11;
            l3 = new Paddle(Paddle::instance()); // adds a new paddle
            l3->setX(400);                       // changes coordinates
            l3->setY(800);
            array = new Brick *[rows];
            init();
            diamondPattern(); // calls the recursive function
        }
    }
    void setLevel(int n) // sets level
    {
        level = n;
        if (n == 1) // for level 1
        {
            fstream input("level1.txt", ios::in);
            int max = 0;
            string s;
            while (getline(input, s))
            {
                int n = stoi(s);
                if (max < n)
                    max = n;
            }
            input.close();
            highscore = max;
            rows = 5, col = 10;
            array = new Brick *[rows];
            for (int i = 0; i < rows; i++)
            {
                array[i] = new Brick[col];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    array[i][j].setLevel(level);
                    array[i][j].setX(100 + j * array[i][j].getWidth());
                    array[i][j].setY(400 + i * array[i][j].getHeight());
                }
            }
        }
        else if (n == 2) // for level 2
        {
            fstream input("level2.txt", ios::in);
            int max = 0;
            string s;
            while (getline(input, s))
            {
                int n = stoi(s);
                if (max < n)
                    max = n;
            }
            input.close();
            highscore = max;
            rows = 15;
            col = 3;
            array = new Brick *[rows];
            for (int i = 0; i < rows; i++)
            {
                array[i] = new Brick[col];
            }
            int w = 0, h = 0;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        array[i * 3 + j][k].setLevel(level);
                        array[i * 3 + j][k].setX(w + 150 + j * array[j][k].getWidth());
                        array[i * 3 + j][k].setY(h + 80 + k * array[j][k].getHeight());
                    }
                }
                if (i < 2)
                {
                    w += 3 * (**array).getWidth();
                    h += 3 * (**array).getHeight();
                }
                else
                {
                    w -= 3 * (**array).getWidth();
                    h += 3 * (**array).getHeight();
                }
            }
            Ball::setX(800);
        }
        else if (n == 3) // for level 3
        {
            fstream input("level3.txt", ios::in);
            int max = 0;
            string s;
            while (getline(input, s))
            {
                int n = stoi(s);
                if (max < n)
                    max = n;
            }
            input.close();
            highscore = max;
            rows = 12, col = 11;
            l3 = new Paddle(Paddle::instance());
            l3->setX(400);
            l3->setY(800);
            array = new Brick *[rows];
            for (int i = 0; i < rows; i++)
            {
                array[i] = new Brick[col];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    array[i][j].setLevel(level);
                    array[i][j].setX(100 + j * array[i][j].getWidth());
                    array[i][j].setY(200 + i * array[i][j].getHeight());
                }
            }
            diamondPattern();
        }
    }

    bool getOver() { return over; }          // returns bool
    Paddle *getPaddle() { return l3; }       // returns extra paddle for level 3
    int getHighscore() { return highscore; } // gets highscore
    int getLevel() { return level; }         // gets the level
    int getLives() { return lives; }         // gets the lives
    void draw()                              // for drawing bricks and foods
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                array[i][j].draw();
                if (array[i][j].getYellow())
                {
                    (array[i][j].getFoods())[0]->draw();
                    (array[i][j].getFoods())[1]->draw();
                    (array[i][j].getFoods())[0]->move();
                    (array[i][j].getFoods())[1]->move();
                }
            }
        }
        if (level == 3)
            l3->draw();
    }
    void incTimer() { timer++; }
    int getTimer() { return timer; }
    void collisionCheck() // for checking collisions of everything
    {
        int ballX = Ball::getX(), ballY = Ball::getY();
        if ((**array).getBricks() == 0) // checks if all bricks are gone
            over = true;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (array[i][j].timerStatus()) // checks if there is a timer active for foods
                {
                    array[i][j].incTimer();
                    if (array[i][j].getTimer() >= 250) // checks if five seconds have passed then reverses powerups
                    {
                        if (array[i][j].getColor() == 'r')
                        {
                            Ball::decVelocity();
                        }
                        if (array[i][j].getColor() == 'b')
                        {
                            Ball::incVelocity();
                        }
                        if (array[i][j].getColor() == 'y')
                        {
                            array[i][j].setYellow(0);
                            delete (array[i][j].getFoods())[0];
                            delete (array[i][j].getFoods())[1];
                            delete[] array[i][j].getFoods();
                        }
                        array[i][j].setTStart(0);
                    }
                }
                if (array[i][j].status()) // for checking if brick is alive
                {
                    if (ballY >= array[i][j].getY() && ballY <= array[i][j].getY() + array[i][j].getHeight() && ((ballX >= array[i][j].getX() && ballX <= array[i][j].getX() + 10) || (ballX <= array[i][j].getX() + array[i][j].getWidth() && ballX >= array[i][j].getX() + array[i][j].getWidth() - 10)))
                    {
                        array[i][j].collide(); // decreases collision count

                        Ball::setColor(array[i][j].getColor()); // bonus color changing
                        switch (getDirection())                 // reversing of directions
                        {
                        case 'e':
                            setDirection('q');
                            break;
                        case 'q':
                            setDirection('e');
                            break;
                        case 'z':
                            setDirection('c');
                            break;
                        case 'c':
                            setDirection('z');
                            break;
                        }
                    }
                    // for side wall checks
                    else if (ballX >= array[i][j].getX() && ballX <= array[i][j].getX() + array[i][j].getWidth() && ballY >= array[i][j].getY() && ballY <= array[i][j].getY() + array[i][j].getHeight())
                    {
                        array[i][j].collide();
                        Ball::setColor(array[i][j].getColor());
                        switch (getDirection())
                        {
                        case 'e':
                            setDirection('c');
                            break;
                        case 'q':
                            setDirection('z');
                            break;
                        case 'z':
                            setDirection('q');
                            break;
                        case 'c':
                            setDirection('e');
                            break;
                        }
                    }
                }
                else if (array[i][j].getYellow()) // for checking if yellow food balls are active
                {
                    for (int k = 0; k < 2; k++) // for collision checks of each ball
                    {
                        for (int l = 0; l < rows; l++)
                        {
                            for (int m = 0; m < col; m++)
                            {
                                if (array[l][m].status())
                                {
                                    ballX = (array[i][j].getFoods())[k]->getX(), ballY = (array[i][j].getFoods())[k]->getY();
                                    if (ballY >= array[l][m].getY() && ballY <= array[l][m].getY() + array[l][m].getHeight() && ((ballX >= array[l][m].getX() && ballX <= array[l][m].getX() + 10) || (ballX <= array[l][m].getX() + array[l][m].getWidth() && ballX >= array[l][m].getX() + array[l][m].getWidth() - 10)))
                                    {
                                        array[l][m].collide();
                                        (array[i][j].getFoods())[k]->setColor(array[l][m].getColor());
                                        switch ((array[i][j].getFoods())[k]->getDirection())
                                        {
                                        case 'e':
                                            (array[i][j].getFoods())[k]->setDirection('q');
                                            break;
                                        case 'q':
                                            (array[i][j].getFoods())[k]->setDirection('e');
                                            break;
                                        case 'z':
                                            (array[i][j].getFoods())[k]->setDirection('c');
                                            break;
                                        case 'c':
                                            (array[i][j].getFoods())[k]->setDirection('z');
                                            break;
                                        }
                                    }
                                    else if (ballX >= array[l][m].getX() && ballX <= array[l][m].getX() + array[l][m].getWidth() && ballY >= array[l][m].getY() && ballY <= array[l][m].getY() + array[l][m].getHeight())
                                    {
                                        array[l][m].collide();
                                        (array[i][j].getFoods())[k]->setColor(array[l][m].getColor());
                                        switch ((array[i][j].getFoods())[k]->getDirection())
                                        {
                                        case 'e':
                                            (array[i][j].getFoods())[k]->setDirection('c');
                                            break;
                                        case 'q':
                                            (array[i][j].getFoods())[k]->setDirection('z');
                                            break;
                                        case 'z':
                                            (array[i][j].getFoods())[k]->setDirection('q');
                                            break;
                                        case 'c':
                                            (array[i][j].getFoods())[k]->setDirection('e');
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        // checking of collision with paddle for extra yellow food balls
                        if (ballX >= Paddle::getX() && ballX <= Paddle::getX() + Paddle::getSize() && ballY <= Paddle::getY() + 30 && ballY >= Paddle::getY() + 10)
                        {
                            (array[i][j].getFoods())[k]->setY(Paddle::getY() + 30); // teleports the ball slightly upward for no glitching
                            switch ((array[i][j].getFoods())[k]->getDirection())    // swapping of balls direction
                            {
                            case 'e':
                                (array[i][j].getFoods())[k]->setDirection('c');
                                break;
                            case 'q':
                                (array[i][j].getFoods())[k]->setDirection('z');
                                break;
                            case 'z':
                                (array[i][j].getFoods())[k]->setDirection('q');
                                break;
                            case 'c':
                                (array[i][j].getFoods())[k]->setDirection('e');
                                break;
                            }
                            Paddle::setColor((array[i][j].getFoods())[k]->getColor());
                        }
                        if (level == 3) // checks if level is 3 than checks the upper paddle as well
                        {
                            if (ballX >= getPaddle()->getX() && ballX <= getPaddle()->getX() + getPaddle()->getSize() && ballY <= getPaddle()->getY() + 30 && ballY >= getPaddle()->getY() + 10)
                            {
                                (array[i][j].getFoods())[k]->setY(getPaddle()->getY() - 10);
                                switch ((array[i][j].getFoods())[k]->getDirection())
                                {
                                case 'e':
                                    (array[i][j].getFoods())[k]->setDirection('c');
                                    break;
                                case 'q':
                                    (array[i][j].getFoods())[k]->setDirection('z');
                                    break;
                                case 'z':
                                    (array[i][j].getFoods())[k]->setDirection('q');
                                    break;
                                case 'c':
                                    (array[i][j].getFoods())[k]->setDirection('e');
                                    break;
                                }
                                getPaddle()->setColor((array[i][j].getFoods())[k]->getColor());
                            }
                        }

                        if (ballX >= 1010) // wall bounce checks
                        {
                            if ((array[i][j].getFoods())[k]->getDirection() == 'e')
                                (array[i][j].getFoods())[k]->setDirection('q');
                            else
                                (array[i][j].getFoods())[k]->setDirection('z');
                        }
                        if (ballX <= 10) // wall bounce checks
                        {
                            if ((array[i][j].getFoods())[k]->getDirection() == 'q')
                                (array[i][j].getFoods())[k]->setDirection('e');
                            else
                                (array[i][j].getFoods())[k]->setDirection('c');
                        }
                        if (ballY >= 840) // wall bounce checks
                        {
                            if (!(level == 3)) // when level is not 3
                            {
                                if ((array[i][j].getFoods())[k]->getDirection() == 'e')
                                    (array[i][j].getFoods())[k]->setDirection('c');
                                else
                                    (array[i][j].getFoods())[k]->setDirection('z');
                            }
                            else // upwards bounce is disabled and lives are lost
                            {
                                if ((array[i][j].getFoods())[k]->getAlive())
                                {
                                    if (Ball::getBalls() < 2)
                                        lives--;
                                    if (lives == 0)
                                        over = true;
                                    (array[i][j].getFoods())[k]->setX(450);
                                    (array[i][j].getFoods())[k]->setY(800);
                                    (array[i][j].getFoods())[k]->setDirection('c');
                                }
                            }
                        }
                        if (ballY <= 10) // life is lost when ball reaches lower
                        {
                            if ((array[i][j].getFoods())[k]->getAlive())
                            {
                                if (Ball::getBalls() < 2)
                                    lives--;
                                if (lives == 0)
                                    over = true;
                                (array[i][j].getFoods())[k]->setX(450);
                                (array[i][j].getFoods())[k]->setY(150);
                                (array[i][j].getFoods())[k]->setDirection('e');
                            }
                            array[i][j].getFood().collide();
                        }
                    }
                }
                // for food collisions with paddle
                else if (array[i][j].getFood().getY() >= Paddle::getY() && array[i][j].getFood().getY() <= Paddle::getY() + 50 && array[i][j].getFood().getX() >= Paddle::getX() && array[i][j].getFood().getX() <= Paddle::getX() + Paddle::getSize())
                {
                    if (array[i][j].getFood().getColor() == 'g') // increase size of paddle for green food
                    {
                        Paddle::setSize(Paddle::getSize() + 30);
                    }
                    else if (array[i][j].getFood().getColor() == 'r') // increases speed for red food for 5 sec
                    {
                        Ball::incVelocity();
                        array[i][j].startTimer();
                    }
                    else if (array[i][j].getFood().getColor() == 'b') // decreases speed for blue food for 5 sec
                    {
                        Ball::decVelocity();
                        array[i][j].startTimer();
                    }
                    else if (array[i][j].getFood().getColor() == 'p') // decrease size of paddle for pink food
                    {
                        Paddle::setSize(Paddle::getSize() - 30);
                    }
                    else if (array[i][j].getFood().getColor() == 'y') // adds two extra balls for yellow food
                    {
                        Ball &obj = Ball::instance();
                        array[i][j].setYellow(1);
                        Ball *a = new Ball(obj);
                        Ball *b = new Ball(obj);
                        (array[i][j].getFoods())[0] = a;
                        (array[i][j].getFoods())[1] = b;
                        switch (getDirection()) // changes direction of balls other than where main ball is going
                        {
                        case 'e':
                            (array[i][j].getFoods())[0]->setDirection('q');
                            (array[i][j].getFoods())[1]->setDirection('z');
                            break;
                        case 'q':
                            (array[i][j].getFoods())[0]->setDirection('e');
                            (array[i][j].getFoods())[1]->setDirection('c');
                            break;
                        case 'z':
                            (array[i][j].getFoods())[0]->setDirection('c');
                            (array[i][j].getFoods())[1]->setDirection('e');
                            break;
                        case 'c':
                            (array[i][j].getFoods())[0]->setDirection('z');
                            (array[i][j].getFoods())[1]->setDirection('q');
                            break;
                        }
                        (array[i][j].getFoods())[0]->setAlive(0);
                        (array[i][j].getFoods())[1]->setAlive(0);
                        array[i][j].startTimer();
                    }
                    array[i][j].getFood().collide();
                }
                // for upper paddle
                if (level == 3 && array[i][j].getFood().getY() >= getPaddle()->getY() && array[i][j].getFood().getY() <= getPaddle()->getY() + 50 && array[i][j].getFood().getX() >= getPaddle()->getX() && array[i][j].getFood().getX() <= getPaddle()->getX() + getPaddle()->getSize())
                {
                    if (array[i][j].getFood().getColor() == 'g')
                    {
                        getPaddle()->setSize(getPaddle()->getSize() + 30);
                    }
                    else if (array[i][j].getFood().getColor() == 'r')
                    {
                        Ball::incVelocity();
                        array[i][j].startTimer();
                    }
                    else if (array[i][j].getFood().getColor() == 'b')
                    {
                        Ball::decVelocity();
                        array[i][j].startTimer();
                    }
                    else if (array[i][j].getFood().getColor() == 'p')
                    {
                        getPaddle()->setSize(getPaddle()->getSize() - 30);
                    }
                    else if (array[i][j].getFood().getColor() == 'y')
                    {
                        Ball &obj = Ball::instance();
                        array[i][j].setYellow(1);
                        Ball *a = new Ball(obj);
                        Ball *b = new Ball(obj);
                        (array[i][j].getFoods())[0] = a;
                        (array[i][j].getFoods())[1] = b;
                        switch (getDirection())
                        {
                        case 'e':
                            (array[i][j].getFoods())[0]->setDirection('q');
                            (array[i][j].getFoods())[1]->setDirection('z');
                            break;
                        case 'q':
                            (array[i][j].getFoods())[0]->setDirection('e');
                            (array[i][j].getFoods())[1]->setDirection('c');
                            break;
                        case 'z':
                            (array[i][j].getFoods())[0]->setDirection('c');
                            (array[i][j].getFoods())[1]->setDirection('e');
                            break;
                        case 'c':
                            (array[i][j].getFoods())[0]->setDirection('z');
                            (array[i][j].getFoods())[1]->setDirection('q');
                            break;
                        }
                        (array[i][j].getFoods())[0]->setAlive(0);
                        (array[i][j].getFoods())[1]->setAlive(0);
                        array[i][j].startTimer();
                    }
                    array[i][j].getFood().collide();
                }
            }
        }
        ballX = Ball::getX(), ballY = Ball::getY();
        // for normal ball paddle bouncing
        if (ballX >= Paddle::getX() && ballX <= Paddle::getX() + Paddle::getSize() && ballY <= Paddle::getY() + 30 && ballY >= Paddle::getY() + 10)
        {
            Ball::setY(Paddle::getY() + 30);
            switch (getDirection())
            {
            case 'e':
                setDirection('c');
                break;
            case 'q':
                setDirection('z');
                break;
            case 'z':
                setDirection('q');
                break;
            case 'c':
                setDirection('e');
                break;
            }
            Paddle::setColor(Ball::getColor());
        }
        if (level == 3) // for upper paddle ball bouncing for level 3
        {
            if (ballX >= getPaddle()->getX() && ballX <= getPaddle()->getX() + getPaddle()->getSize() && ballY <= getPaddle()->getY() + 30 && ballY >= getPaddle()->getY() + 10)
            {
                Ball::setY(getPaddle()->getY() - 10);
                switch (getDirection())
                {
                case 'e':
                    setDirection('c');
                    break;
                case 'q':
                    setDirection('z');
                    break;
                case 'z':
                    setDirection('q');
                    break;
                case 'c':
                    setDirection('e');
                    break;
                }
                getPaddle()->setColor(Ball::getColor());
            }
        }
        if (ballX >= 1010) // wall bouncing
        {
            if (getDirection() == 'e')
                setDirection('q');
            else
                setDirection('z');
        }
        if (ballX <= 10) // wall bouncing
        {
            if (getDirection() == 'q')
                setDirection('e');
            else
                setDirection('c');
        }
        if (ballY >= 840) // wall bouncing
        {
            if (!(level == 3)) // for when level is not 3
            {
                if (getDirection() == 'e')
                    setDirection('c');
                else
                    setDirection('z');
            }
            else // decreases lives if level is 3
            {
                if (Ball::getAlive())
                {
                    if (Ball::getBalls() < 2)
                        lives--;
                    if (lives == 0)
                        over = true;
                    Ball::setX(450);
                    Ball::setY(800);
                    setDirection('c');
                }
            }
        }
        if (ballY <= 10) // decreases lives
        {
            if (Ball::getAlive())
            {
                if (Ball::getBalls() < 2)
                    lives--;
                if (lives == 0)
                    over = true;
                Ball::setX(450);
                Ball::setY(150);
                setDirection('e');
            }
        }
    }

    ~Level() // destructor
    {
        for (int i = 0; i < rows; i++)
            delete[] array[i];
        delete[] array;
        if (level == 1) // stores score for level 1
        {
            fstream output("level1.txt", ios::app);
            output << Brick::getScore() << endl;
            output.close();
        }
        else if (level == 2) // stores score for level 2
        {
            fstream output("level2.txt", ios::app);
            output << Brick::getScore() << endl;
            output.close();
        }
        if (level == 3) // stores score for level 3
        {
            fstream output("level3.txt", ios::app);
            output << Brick::getScore() << endl;
            output.close();
        }
    }
} a(-1);
#endif LEVEL_H