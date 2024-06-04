#ifndef _ENEMIES_H
#define _ENEMIES_H

#include "Game_objects.h"

class Enemies : public Game_objects
{
    int width;
    int height;
public:
    Enemies(int x, int y);
    void draw();
    void moveDown();
    int getX();
    int getY();
    int getWidth();
    int getHeight();

	~Enemies();
};

#endif // _ENEMIES_H

