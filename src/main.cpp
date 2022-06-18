#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "controls.cpp"
#include "OnScreenRender.cpp"

int main(int, char **)
{
    SDL_Window *window = NULL;
    SDL_GLContext context = NULL;

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

    
    int x = 0;
    int y = 0;


    

    Player(x, y, window, context);

    while (true)
    { 
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return 0;
            }
            commands(event);
            switch (commands(event))
            {
            case -1:
                std::cout << "Escape pressed" << std::endl;
                return 0;
            case 1:
                std::cout << "Up" << std::endl;
                y++;
                break;
            case 2:
                std::cout << "Down" << std::endl;
                y--;
                break;
            case 3:
                std::cout << "Left" << std::endl;
                x--;
                break;
            case 4:
                std::cout << "Right" << std::endl;
                x++;
                break;
            case 5:
                std::cout <<"X = " << x << " | Y = " << y << std::endl;
            }

            glClear(GL_COLOR_BUFFER_BIT);
            SDL_GL_SwapWindow(window);
           

        } 
    }

    return 0;
}
