#ifndef _BULLETS_H
#define _BULLETS_H

#include "Game_objects.h"
class Bullets : public Game_objects
{
private:
    int speed;
    int radius;
    
public:
	Bullets(int x, int y);
	~Bullets();
    int getX();
    int getY();
    void draw();
    void moveUp();

    int getRadius();

};

#endif

