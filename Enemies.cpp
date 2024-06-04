#include "Enemies.h"
#include <raylib.h>

Enemies::Enemies(int x, int y) : Game_objects(x, y), width(30) ,height(30) {}

void Enemies::draw()
{
	DrawRectangle(x, y, width, height, {0 , 0 ,0 ,255});

}

void Enemies::moveDown()
{
	y += 4;
}

int Enemies::getX()
{
	return x;
}

int Enemies::getY()
{
	return y;
}

int Enemies::getWidth()
{
	return width;
}

int Enemies::getHeight()
{
	return height;
}

Enemies::~Enemies()
{
}

