#include <iostream>
#include <SDL2/SDL.h>

#include "Game.hpp"


using namespace std;



int main()
{
    const int fps = 60;
    const int frameDelay = 1000/fps;

    Uint32 frameStart;
    int frameTime;

    Game *game = new Game();
    game->initialize("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 640, false);

    while(game->running()){

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}