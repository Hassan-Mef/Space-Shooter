#include "Bullets.h"
#include <raylib.h>
#include <iostream>

using namespace std;


Bullets::Bullets(int x, int y): Game_objects(x, y)
{
	speed = 10;
	radius = 3;
}

Bullets::~Bullets()
{
}

int Bullets::getX()
{
	return x;
}

int Bullets::getY()
{
	return y;
}

void Bullets::draw()
{
	Color White = Color{ 120 , 255 , 255 ,255 };
	DrawCircle(x, y, radius ,White);

}

void Bullets::moveUp()
{
	y -= speed;

}

int Bullets::getRadius()
{
	return radius;
}

