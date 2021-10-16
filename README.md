# Snake-Game
Small classic snake game built using C++ and SDL2

# Installation
Make sure that both g++ and SDL2 are installed then open terminal and run the following:
'''
g++ "Source code/main.cpp" "Source code/particle.cpp" "Source code/screen.cpp" "Source code/snake.cpp" -o Executable/snake `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
'''
