#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL2/SDL.h>

namespace SDL_Graphics
{
class screen
{
public:
  const static int WIDTH = 400;
  const static int HEIGHT = 300;
  const static int PIXELS = WIDTH * HEIGHT;
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  //Uint32 *buffer;
  Uint32 *buffer2;

public:
    Uint32 *buffer;
    SDL_Surface* surface;
  screen();
  bool init();
  void setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
  unsigned int color(unsigned char red, unsigned char green, unsigned char blue);
  void blur();
  void boxBlur();
  void update();
  void clear();
  bool exitEvent();
  SDL_Event getLastEvent(); 
  SDL_Surface *windowSurface = nullptr;
  void close();
  void setWindowTitle(const char *text);
};
} // namespace SDL_Graphics

#endif