#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_atomic.h>
#include <SDL_events.h>

#include <iostream>
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Rect rect;
SDL_Rect rect1;

void drawCircle(int cX, int cY, int r) {
    int x = r;
    int y = 0;
    int d = 1 - x;
    while (y <= x) {
        SDL_Point points[8] = {
            {cX - x, cY - y}, {cX - x, cY + y},
            {cX + x, cY - y}, {cX + x, cY + y},
            {cX - y, cY - x}, {cX - y, cY + x},
            {cX + y, cY - x}, {cX + y, cY + x}
        };
        SDL_RenderDrawPoints(renderer, points, 8);

        y++;
        if (d <= 0) {
            d += 2 * y + 1;
        }
        else {
            x--;
            d += 2 * (y - x) + 1;
        }
    }
}


void handleInput(bool& isRunning, bool& moveLeft, bool& moveRight, bool& moveUp, bool& moveDown) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }

            else if (event.key.keysym.sym == SDLK_LEFT) {
                moveLeft = true;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT) {
                moveRight = true;
            }
            else if (event.key.keysym.sym == SDLK_UP) {
                moveUp = true;
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
                moveDown = true;
            }
        }
        else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT) {
                moveLeft = false;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT) {
                moveRight = false;
            }
            else if (event.key.keysym.sym == SDLK_UP) {
                moveUp = false;
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
                moveDown = false;
            }
        }
    }
}

    void move(SDL_Rect & rect, bool moveLeft, bool moveRight, bool& moveUp, bool& moveDown) {
        if (moveLeft) {
            rect.x -= 5;
            if (rect.x < 0)
                rect.x = 800 - 200;
        }
        else if (moveRight) {
            rect.x += 5;
            if (rect.x + 200 > 800)
                rect.x = 0;
        }
        else if (moveUp) {
			rect.y -= 5;
			if (rect.y < 0)
				rect.y = 600 - 200;
        }
        else if (moveDown) {
            rect.y += 5;
            if (rect.y + 200 > 600)
                rect.y = 0;
        }
    }
void move1(SDL_Rect& rect1) {
	rect1.x += 5;
	if (rect1.x + 100 > 800)
		rect1.x = 0;
	rect1.y += 5;
	if (rect1.y + 100 > 600)
		rect1.y = 0;
}

void render() {
    // Clear screen with yellow color
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Yellow
    SDL_RenderClear(renderer);
    // Draw a line
    // SDL_RenderDrawLineF(renderer, 4, 5, 174, 305);
    
    // Draw a point at (10, 305)
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black for visibility
    //SDL_RenderDrawPoint(renderer, 10, 305);

    // Draw a blue rectangle
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue
    SDL_RenderFillRect(renderer, &rect);

    // Draw a red rectangle inside the blue 
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red
    SDL_RenderFillRect(renderer, &rect1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black
 //  // draw connected lines using SDL_RenderDrawLines
        SDL_Point points[5] = {
            {100, 300}, {200, 400}, {300, 300}, {400, 400}, {500, 300}
    };
    SDL_RenderDrawLines(renderer, points, 5);
 //      
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red
    drawCircle(300, 300, 100);
 //   // Update the renderer to display changes
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
    rect = { 5, 5, 200, 200 };
    rect1 = { 25, 25, 100, 100 };
    bool isRunning = true;
	bool moveLeft = false;
	bool moveRight = false;
	bool moveUp = false;
	bool moveDown = false;
    while (isRunning) {
        handleInput(isRunning,moveLeft,moveRight,moveUp,moveDown); // Handle window events
		move(rect,moveLeft,moveRight,moveUp,moveDown);              // Move the rectangle
        move1(rect1);
        render();               // Render graphics
        SDL_Delay(16);          // Small delay for ~60 FPS rendering
    }

    SDL_DestroyRenderer(renderer); // Destroy the renderer
    SDL_DestroyWindow(window);     // Destroy the window
    SDL_Quit();                    // Quit SDL
    return 0;
}
