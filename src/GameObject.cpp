#include "GameObject.hpp"
#include "Texture.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y){
    
    textureObj = Texture::loadTexture(texturesheet); 
    xpos = x;
    ypos = y;
}

void GameObject::update(){
   
    xpos++;
    ypos++;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.w = srcRect.w * 2;
    dstRect.h = srcRect.h * 2;

}

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, textureObj, &srcRect, &dstRect);
}