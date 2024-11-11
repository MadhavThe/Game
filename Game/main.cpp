#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

void handleInput(bool& isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void render() {
    // Clear screen with yellow color
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Yellow
    SDL_RenderClear(renderer);
    // Draw a line
    // SDL_RenderDrawLineF(renderer, 4, 5, 174, 305);
    
    // Draw a point at (10, 305)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black for visibility
    SDL_RenderDrawPoint(renderer, 10, 305);

    // Draw a blue rectangle
    SDL_Rect rect = { 5, 5, 400, 400 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue
    SDL_RenderFillRect(renderer, &rect);

    // Draw a red rectangle inside the blue one
    SDL_Rect rect1 = { 25, 25, 100, 100 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red
    SDL_RenderFillRect(renderer, &rect1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black
   // draw connected lines using SDL_RenderDrawLines
        SDL_Point points[5] = {
            {100, 300}, {200, 400}, {300, 300}, {400, 400}, {500, 300}
    };
    SDL_RenderDrawLines(renderer, points, 5);

    // Update the renderer to display changes
    SDL_RenderPresent(renderer);
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool isRunning = true;
    while (isRunning) {
        handleInput(isRunning); // Handle window events
        render();               // Render graphics
        SDL_Delay(16);          // Small delay for ~60 FPS rendering
    }

    SDL_DestroyRenderer(renderer); // Destroy the renderer
    SDL_DestroyWindow(window);     // Destroy the window
    SDL_Quit();                    // Quit SDL
    return 0;
}
