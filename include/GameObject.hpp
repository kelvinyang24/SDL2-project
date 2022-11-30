#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();

    void update();
    void render();

private:
    int xpos;
    int ypos;
    
    SDL_Texture *textureObj;
    SDL_Rect srcRect, dstRect;


};





#endif