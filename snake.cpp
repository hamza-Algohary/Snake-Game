#include "screen.h"
#include "snake.h"
#include "particle.h"
#include <iostream>

using namespace std;
using namespace SDL_Graphics;

Snake::Snake(){
    internalBuffer = new int[screen::HEIGHT*screen::WIDTH];
    image = new Uint32[screen::HEIGHT*screen::WIDTH];
    length = 15;
    x = 0;
    y = 0;
    direction = 0;
    lastPosition = -1;
    lastDirection = -1;
    score = 0;
    particle0 = new particle(screen::WIDTH,screen::HEIGHT); 

}

void Snake::setDirection(int dir){
    if(!((dir+lastDirection)%2 == 0)){
        direction = dir;
    }
}

void Snake::move(){

    if(x<=-1||x>=1){
        x = -x;
    }
    if(y<=-1||y>=1){
        y = -y;
    }
    if(direction == 0){
        x +=0.001;
    }else if(direction == 1){
        y -=0.001;
    }else if(direction == 2){
        x -= 0.001;
    }else if(direction == 3){
        y += 0.001;
    }
    lastDirection = direction;

    for (int i=0;i<screen::WIDTH*screen::HEIGHT;i++){
        if(internalBuffer[i] > 0){
            (internalBuffer[i])--;
        }else if(internalBuffer[i] < 0){
            (internalBuffer[i])++;
        }

    }
    int real_x = (x+1)*(screen::WIDTH/2);
    int real_y = (y+1)*(screen::HEIGHT/2);
    int position = real_x+(real_y*screen::WIDTH);
    if( (position != lastPosition) && (internalBuffer[position]>0)){
        throw -1;
    }

    //if(position == (particle0->x)+(particle0->y*screen::WIDTH)){
    if(image[position] == 0xffff0000){
        length += 10;
        score += length*10;
        particle0->renew();
    }
    if(direction==1 || direction==3){
    for(int i=-1;i<=1;i++){
        internalBuffer[(position+i)] = length*-1;
    }
    }else if(direction==0 || direction==2){
    for(int i=-1;i<=1;i++){
        internalBuffer[position+(i*screen::WIDTH)] = length*-1;
    }
    }
    internalBuffer[position] = length;
    lastPosition = position;
     //cout << "position" << position << endl;
     //cout << "x: " << real_x << " y: " << real_y <<endl;
}

void Snake::updateSnake(){
    memset(image , 0 , screen::WIDTH*screen::HEIGHT*sizeof(Uint32));
    for(int i=-1;i<=1;i++){
        image[((particle0->x)+(particle0->y*screen::WIDTH))+i] = 0xffff0000;
    }
    for (int i = -1; i <= 1; i+=2)
    {
        image[((particle0->x)+(particle0->y*screen::WIDTH))+(i*screen::WIDTH)] = 0xffff0000;
    }
    
    
    for(int i=0;i<screen::WIDTH*screen::HEIGHT;i++){
        if(internalBuffer[i]!=0){
            image[i] = 0xff000000;
        }
    }
    cout << particle0->x << " " << particle0->y << " position in buffer: " << (particle0->x)+(particle0->y*screen::WIDTH) << endl;
}