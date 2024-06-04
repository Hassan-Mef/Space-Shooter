#ifndef _SHIP_H
#define _SHIP_H

#include <iostream>
#include <string>
#include <raylib.h>
#include "Game_objects.h"

using namespace std;

class Ship : public Game_objects
{
	int width;
	int height;
public:
	Ship(int x, int y);
	void draw() override;
	void moveLeft();
	void moveRight(int gameWidth);
	int getWidth();
	int getHeight();
	int getX();
	int getY();


	

};



#endif



