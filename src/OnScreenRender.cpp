#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>



void Player( int x,int y, SDL_Window* window, SDL_GLContext context ) {

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(renderer);
    SDL_Rect Player = {0 + x, 0 + y, 100, 100};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &Player);
    SDL_RenderPresent(renderer);

}

  


