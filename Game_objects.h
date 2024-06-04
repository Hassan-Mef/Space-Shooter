#ifndef _GAME_OBJECTS_H
#define _GAME_OBJECTS_H

#include <iostream>
#include <string>
#include <raylib.h>
using namespace std;

class Game_objects
{
protected:
	int x, y;

public:
	Game_objects(int x, int y);
	virtual void draw() = 0;

};


#endif

