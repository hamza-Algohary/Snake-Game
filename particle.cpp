#include <cstdlib>
#include "particle.h"
#include "screen.h"

using namespace SDL_Graphics;

particle::particle(int width , int height){
    x = rand() % 400;
    y = rand() % 300;
}

void particle::renew(){
    x = rand() % 400;
    y = rand() % 300;
}
