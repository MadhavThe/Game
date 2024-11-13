#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "App.hpp"
#include "Input.hpp"
#include "Movement.hpp"
#include "Renderer.hpp"


int main(int argc, char* args[]) {
    App app;
    if (!app.init()) return 1;

    SDL_Rect rect = { 5, 5, 200, 200 };
    SDL_Rect rect1 = { 25, 25, 100, 100 };

    bool isRunning = true, moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
    Input input;

    while (isRunning) {
        input.handleInput(isRunning, moveLeft, moveRight, moveUp, moveDown);
        move(rect, moveLeft, moveRight, moveUp, moveDown);
        move1(rect1);
        render(app.getRenderer(), rect, rect1);
        SDL_Delay(16);
    }
    app.cleanup();
    return 0;
}
