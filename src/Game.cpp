#include "../include/Game.hpp"
#include "../include/Texture.hpp"
#include "../include/GameObject.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;

Game::Game(){

}

Game::~Game(){

}

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;

void Game::initialize(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "SDL Initialized" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if (window){
            cout << "Window Successfully Created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            cout << "Renderer Successfully Created" << endl;
        }
        
        isRunning = true;
    }
    
    else{
        isRunning = false;
        cout << "SDL Failed to initialize" << endl;
    }
    
    player = new GameObject("assets/player.xcf", 50, 50);
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::update(){
   player->update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    // Put things to render here:
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned" << endl;
}

bool Game::running(){
     return isRunning;
}