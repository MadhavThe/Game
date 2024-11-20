#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SDL2/SDL.h>
#include <SDL_render.h>

class Character {
private:
    int x, y; // Position
    int w, h; // Size
    SDL_Color color; // Color
    SDL_Renderer* renderer; // Renderer

public:
    Character(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color);
    //void handleInput(bool& isRunning, bool& moveLeft, bool& moveRight, bool& moveUp, bool& moveDown);
    void moveCharacter(bool moveLeft, bool moveRight, bool moveUp, bool moveDown);
    void render();
};

#endif // CHARACTER_HPP