#ifndef SNAKE_H_
#define SNAKE_H_
#include "screen.h"
#include "particle.h"

class Snake
{
private:
    
public:  
    int *internalBuffer;
    Uint32 *image;

    double x,y;

    int length;
    int direction;
    int lastPosition;
    int lastDirection;

    int score;
    particle *particle0;     
    Snake();
    void setDirection(int dir);
    void move();
    void updateSnake();

    
};


#endif