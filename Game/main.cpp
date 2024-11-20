#include "App.hpp"
#include "Input.hpp"
#include "Character.hpp"
#include "Movement.hpp"

int main(int argc, char* args[]) {
    App app;
    if (!app.init()) return 1;

    SDL_Color red = { 255, 0, 0, 255 }; // Character color (Red)
    Character character(app.getRenderer(), 100, 100, 50, 50, red);

    bool isRunning = true;
    bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
    Input input;

    while (isRunning) {
        input.handleInput(isRunning, moveLeft, moveRight, moveUp, moveDown);

        // Update the character's position and render it
        character.handleInput(isRunning, moveLeft, moveRight, moveUp, moveDown);

        SDL_SetRenderDrawColor(app.getRenderer(), 255, 255, 255, 255); // Clear the screen with white
        SDL_RenderClear(app.getRenderer());

        // Render the character
        character.render();

        SDL_RenderPresent(app.getRenderer());
        SDL_Delay(16); // ~60 FPS
    }

    app.cleanup();
    return 0;
}
