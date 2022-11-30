#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"

class Texture{

public:
    static SDL_Texture* loadTexture(const char* filename);
};

#endif