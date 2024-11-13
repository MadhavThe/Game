#include "Input.hpp"

void Input::handleInput(bool& isRunning, bool& moveLeft, bool& moveRight, bool& moveUp, bool& moveDown) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
            else if (event.key.keysym.sym == SDLK_LEFT) moveLeft = true;
            else if (event.key.keysym.sym == SDLK_RIGHT) moveRight = true;
            else if (event.key.keysym.sym == SDLK_UP) moveUp = true;
            else if (event.key.keysym.sym == SDLK_DOWN) moveDown = true;
        }
        else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT) moveLeft = false;
            else if (event.key.keysym.sym == SDLK_RIGHT) moveRight = false;
            else if (event.key.keysym.sym == SDLK_UP) moveUp = false;
            else if (event.key.keysym.sym == SDLK_DOWN) moveDown = false;
        }
    }
}
