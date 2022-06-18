#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
int commands(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            return -1;
        }
        if (event.key.keysym.sym == SDLK_UP) {
            return 1;
        }
        if (event.key.keysym.sym == SDLK_DOWN) {
            return 2;
        }
        if (event.key.keysym.sym == SDLK_LEFT) {
            return 3;
        }
        if (event.key.keysym.sym == SDLK_RIGHT) {
            return 4;
        }
        if (event.key.keysym.sym == SDLK_i) {
            return 5;
        }
    }
    return 0;
}





