#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

class Game{

public:
    Game();
    ~Game();

    void initialize(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
    static SDL_Renderer *renderer;
    int test;

private:
    bool isRunning;
    SDL_Window *window;
};

#endif