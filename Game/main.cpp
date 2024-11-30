#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "App.hpp"
#include "Input.hpp"
#include "Movement.hpp"
#include "Character.hpp"

int main(int argc, char* args[]) {
    App app;
    if (!app.init()) return 0;

    // Set the background color (for clearing the screen)
    SDL_SetRenderDrawColor(app.getRenderer(), 255, 255, 255, 255);  // White background

    SDL_Color red = { 255, 0, 0, 255 };  // Red color for the character
    bool isRunning = true, moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
    Input input;
    Character character(app.getRenderer(), 100, 100, 100, 100, red);

    while (isRunning) {
        input.handleInput(isRunning, moveLeft, moveRight, moveUp, moveDown);  // Handle user input

        // Move the character based on input
        character.moveCharacter(moveLeft, moveRight, moveUp, moveDown);

        // Clear the screen and render the character
        SDL_RenderClear(app.getRenderer());
        character.render();  // Draw the character

        SDL_RenderPresent(app.getRenderer());  // Present the renderer to display the changes
        SDL_Delay(16);  // Delay for ~60 FPS
    }

    app.cleanup();
    return 0;
}
