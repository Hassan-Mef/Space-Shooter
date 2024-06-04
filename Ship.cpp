#include "Ship.h"
#include <iostream>

using namespace std;

Ship::Ship(int x, int y) : Game_objects(x, y)
{
    this->x = x  ;
    this->y = y ;
    width = 30;
	height = 30;
}

void Ship::draw()
{
	DrawRectangle(x, y, width, height, BLUE);
}

void Ship::moveLeft()
{
      x -=5;
      if (x < 13)
      {
		  x = 13;
      }
    
}

void Ship::moveRight(int gameWidth)
{ 
      x+=5;
      if (x > gameWidth - width)
      {
		  x = gameWidth - width;
      }
    
}

int Ship::getWidth()
{
    return width;
}

int Ship::getHeight()
{
	return height;
}

int Ship::getX()
{
    return x;
}

int Ship::getY()
{
    return y;
}


