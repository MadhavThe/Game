#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_MOUSE_FOCUS);
    if (!window) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* render1 = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!render1) {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    
    SDL_SetRenderDrawColor(render1, 255, 255, 0, 255);  // Set draw color to yellow for visibility
    SDL_RenderDrawPoint(render1, 4, 6); // Draw a point at (0, 0)

    //SDL_RenderDrawLineF(render1,4,5,174,305); // for line 
    SDL_RenderPresent(render1);  // Update the renderer to display the point

    SDL_Delay(3000);   // Wait for 3000ms (3 seconds)

    SDL_DestroyRenderer(render1);  // Destroy the renderer
    SDL_DestroyWindow(window);     // Destroy the window
    SDL_Quit();                    // Quit SDL
    return 0;
}
