#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <cstdlib>
#include <sstream>
#include "screen.h"
#include "snake.h"
#include "particle.h"

using namespace SDL_Graphics;
using namespace std;

int main(){
    stringstream text;
    srand(time(0));
    screen screen0;

    Snake snake;
    bool quit = 0;

    if(screen0.init() == false){
        cout << "ERR\n";
    }
    SDL_Event event;

    while(!quit){
        screen0.clear();
        try{ //code for making the player lose if the snke hits its body
            snake.move();
        }catch(int x){
            if(x==-1){
                cout << "Your score is:" << snake.score << endl;
                
                return 0;
            }   
        }
        //cout << 1 << " ";
        snake.updateSnake();
        

        //cout << 2 << " ";
        //screen0.setPixel(((snake.x+1)*(screen0.WIDTH))/2,((snake.y+1)*(screen0.HEIGHT))/2,230,30,50);
            for(int i=0;i<screen::WIDTH*screen::HEIGHT;i++){
                    screen0.buffer[i]=snake.image[i];
            }
        screen0.update();
        //cout << 3 << " ";
        //if(screen0.exitEvent()==false){
        //    break;
        //}
        SDL_Event event;

        while(SDL_PollEvent(&event)){
               stringstream text;
               text << "Score :" << snake.score;
               string title = text.str();
               screen0.setWindowTitle(title.c_str());
               if(event.type == SDL_QUIT){
                    cout << "Good Bye.\n";
                    quit = 1;
               }
               if(event.type == SDL_KEYDOWN){
                    cout << "A key was pressed\n";
                    switch(event.key.keysym.sym){
                         case SDLK_UP   : /*cout << "UP\n";*/    snake.setDirection(1); break;
                         case SDLK_DOWN : /*cout << "DOWN\n";*/  snake.setDirection(3); break;
                         case SDLK_RIGHT: /*cout << "RIGHT\n";*/ snake.setDirection(0); break;
                         case SDLK_LEFT : /*cout << "LEFT\n";*/  snake.setDirection(2); break; 
                    }
                    
               }
               
               
          }
          //cout << snake.direction <<  endl;
    }
              return 0;

}
        
        //cout << event.type << " " << event.key.keysym.sym << " ";
        //cout << snake.x+1*screen0.WIDTH/2 << " " << snake.y+1*screen0.HEIGHT /2<< endl; 
        //screen0.clear();
        //cout << 4 << " ";
        //cout << endl << snake.x << " " << snake.y <<endl;
    
   
        //cout << endl;
        //for(int i = 0;i<screen0.WIDTH*screen0.HEIGHT;i++){
            
        //    if(snake.internalBuffer[i]!=0){
        //        cout << i << ": " << snake.internalBuffer[i] <<  endl;
        //    }
        //}
        //cout << "End of snake buffer" << endl;

        //for(int i = 0;i<screen0.WIDTH*screen0.HEIGHT;i++){
        //    if(screen0.buffer[i]!=0){
        //        cout << i << ": " << screen0.buffer[i] <<  endl;
        //    }
        //}
        //cout << snake.x+1*screen0.WIDTH/2 << " " << snake.y+1*screen0.HEIGHT /2<< endl; 
        //screen0.close();
        //cout << 5 << " ";
    
   /*
     bool running = 1; // if the program is running or not
     SDL_Event event; // A data type for storing the events
     SDL_Init(SDL_INIT_VIDEO); // initalizing SDL

     unsigned int* buffer[screen::WIDTH*screen::HEIGHT]; // The buffer for the screen

     Snake snake; // defining the snake

     memset(buffer ,0 , screen::WIDTH*screen::HEIGHT*sizeof(Uint32) ); //clearing the buffer of the screen 
     
     snake.move(snake.direction); // moving the head of the snake according to direction
     snake.updateSnake(); // updating the internal buffer and the image of the snake


     SDL_Window * window = SDL_CreateWindow("Keyboard handling" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 800 , 600 , SDL_WINDOW_OPENGL);
     SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
     SDL_Texture * texture = SDL_CreateTexture(renderer , SDL_PIXELFORMAT_RGBA8888 , SDL_TEXTUREACCESS_STATIC , 800 , 600);
    


     while(running){
         memset(buffer ,0 , screen::WIDTH*screen::HEIGHT*sizeof(Uint32) ); //clearing the buffer of the screen 
     
         snake.move(snake.direction); // moving the head of the snake according to direction
         snake.updateSnake(); // updating the internal buffer and the image of the snake
         
         SDL_UpdateTexture(texture, NULL, buffer, WIDTH * sizeof(Uint32));
         SDL_RenderClear(renderer);
         SDL_RenderCopy(renderer, texture, NULL, NULL);
         SDL_RenderPresent(renderer);

          while(SDL_PollEvent(&event)){
               if(event.type == SDL_QUIT){
                    cout << "Good Bye.\n";
                    running = 0;
               }
               if(event.type == SDL_KEYDOWN){
                    cout << "A key was pressed\n";
                    switch(event.key.keysym.sym){
                         case SDLK_UP   : cout << "UP\n";   break;
                         case SDLK_DOWN : cout << "DOWN\n"; break;
                         case SDLK_RIGHT: cout << "RIGHT\n";break;
                         case SDLK_LEFT : cout << "LEFT\n"; break;
                    }
                    
               }
          }
     }

     delete [] buffer;
     SDL_DestroyTexture(texture);
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
     */


//    return 0;
//}