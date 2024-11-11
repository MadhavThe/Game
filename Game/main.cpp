#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

//typedef struct SDL_Rect
//{
//    int x, y;
//    int w, h;
//} SDL_Rect;

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

    // Draw a point at (4, 6)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black for visibility
    SDL_RenderDrawPoint(renderer, 10, 305);

    // Draw a line
   /* SDL_RenderDrawLineF(renderer, 4, 5, 174, 305);*/
    //SDL_RenderDrawRect(renderer,rect);
	// Draw a rectangle
    SDL_Rect rect = { 5, 5, 400, 400 };
	  // Blue
       SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	   SDL_RenderFillRect(renderer, &rect);
       SDL_Rect rect1 = { 25,25,100,100 };
       SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	   SDL_RenderFillRect(renderer, &rect1);
    // Update the renderer to display
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);   // Wait for 3000ms (3 seconds)
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
    }

    SDL_DestroyRenderer(renderer); // Destroy the renderer
    SDL_DestroyWindow(window);     // Destroy the window
    SDL_Quit();                    // Quit SDL
    return 0;
}
