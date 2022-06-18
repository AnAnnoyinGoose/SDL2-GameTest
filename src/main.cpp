#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "controls.cpp"
#include "OnScreenRender.cpp"

// compile command: g++ src/main.cpp -lSDL2 -lGL -o out/game.o 

int main(int, char **)
{
    SDL_Window *window = NULL;
    SDL_GLContext context = NULL;
    SDL_Event event;
    SDL_Renderer* renderer = NULL;

    int x = 0;
    int y = 0;
    int command = 0;
    bool quit = false;



    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    context = SDL_GL_CreateContext(window);
    if (context == NULL)
    {
        std::cout << "OpenGL context could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        
        command = commands(event);
        switch (command)
        {
            case -1:
                return 0;
                break;
            case 1:
                y -= 5;
                break;
            case 2:
                y += 5;
                break;
            case 3:
                x -= 5;
                break;
            case 4:
                x += 5;
                break;
            case 5:
                std::cout << "x: " << x << " y: " << y << std::endl;
            default:
                break;
        }
        Player(x, y, window, context);

    }
}
