#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* Texture::loadTexture(const char* filename){

    SDL_Surface* tmpSurface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}