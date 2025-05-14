#ifndef BRICK
#define BRICK
#include "util.h"
#include "level.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GameDisplay()
{

	glClearColor(255, 255, 255, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (a.Menu::getOnscreen())
	{
		a.Menu::draw();
	}
	else if (!a.getOver())
	{
		Ball &ball = a;														 // polymorphism
		Paddle &paddle = a;													 // polymorphism
		Brick &brick = a;													 // polymorphism
		DrawString(20, 800, "Score:", colors[BLACK]);						 // score
		DrawString(100, 800, Num2Str(Brick::getScore()), colors[BLACK]);	 // score
		DrawString(20, 750, "Highscore:", colors[BLACK]);					 // highscore
		DrawString(150, 750, Num2Str(a.getHighscore()), colors[BLACK]);		 // highscore
		DrawString(700, 800, "Lives:", colors[BLACK]);						 // lives
		DrawString(800, 800, Num2Str(a.getLives()), colors[BLACK]);			 // lives
		DrawString(800, 20, "23i-2536", colors[BLACK]);						 // roll number
		DrawString(20, 20, "Muhammad Ibrahim Kiani", colors[BLACK]);		 // name
		DrawRectangle(20, 300, 30, 400, colors[BLACK]);						 // score bar
		DrawLine(30, 300, 30, 300 + Brick::getScore(), 30, colors[MAGENTA]); // score bar
		ball.draw();														 // draws ball
		paddle.draw();														 // draws paddle
		brick.draw();														 // draws bricks
		ball.move();														 // moves ball
		ball.collisionCheck();												 // checks for collision
	}
	else
	{
		if (a.getLives() == 0) // for game lost screen
		{
			DrawRoundRect(0, 0, 1020, 840, colors[BLACK], 100);
			DrawString(450, 450, "You have died.", colors[WHITE]);
			DrawString(450, 350, "Final score:", colors[WHITE]);
			DrawString(580, 350, Num2Str(Brick::getScore()), colors[WHITE]);
			DrawString(450, 400, "Highscore:", colors[WHITE]);
			DrawString(580, 400, Num2Str(a.getHighscore()), colors[WHITE]);
			a.incTimer();
			if (a.getTimer() >= 250)
				exit(0);
		}
		else // for game won screen
		{
			DrawRoundRect(0, 0, 1020, 840, colors[BLACK], 100);
			DrawString(450, 450, "You have won!", colors[WHITE]);
			DrawString(450, 350, "Final score:", colors[WHITE]);
			DrawString(580, 350, Num2Str(Brick::getScore()), colors[WHITE]);
			DrawString(450, 400, "Highscore:", colors[WHITE]);
			DrawString(580, 400, Num2Str(a.getHighscore()), colors[WHITE]);
			a.incTimer();
			if (a.getTimer() >= 250)
				exit(0);
		}
	}
	glutSwapBuffers();
}

void NonPrintableKeys(int key, int x, int y)
{
	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y)
{
	if (a.getLevel() == 3)
	{
		switch (key) // for movement of upper paddle in level 3
		{
		case 'a':
			if (a.getPaddle()->getX() >= 0)
				a.getPaddle()->setX(a.getPaddle()->getX() - a.getPaddle()->getSize() / 2);
			break;
		case 'd':
			if (a.getPaddle()->getX() <= 1024 - a.getPaddle()->getSize())
				a.getPaddle()->setX(a.getPaddle()->getX() + a.getPaddle()->getSize() / 2);
			break;
		}
	}
	if (a.getOnscreen())
	{
		if (key == '1')
		{
			a.setLevel(1);
			a.setOnscreen(0);
		}
		else if (key == '2')
		{
			a.setLevel(2);
			a.setOnscreen(0);
		}
		else if (key == '3')
		{
			a.setLevel(3);
			a.setOnscreen(0);
		}
	}
	if (key == 'p' || key == 'p') // Key for placing the bomb
	{
	}
	glutPostRedisplay();
}

void Timer(int m)
{
	glutPostRedisplay();
	glutTimerFunc(1000.0 / FPS, Timer, 0);
}

void MousePressedAndMoved(int x, int y)
{
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	if (x < 1020 - a.Paddle::getSize())
		a.Paddle::setX(x);

	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y)
{

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{

	int width = 1020, height = 840;
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("OOP Project");
	SetCanvasSize(width, height);

	glutDisplayFunc(GameDisplay);
	glutIdleFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0 / FPS, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);
	glutMotionFunc(MousePressedAndMoved);

	glutMainLoop();
	return 1;
}
#endif BRICK
