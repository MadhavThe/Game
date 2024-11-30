#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL2/SDL.h>

class Character {
private:
    SDL_Renderer* renderer;
    int x, y;  // Position
    int w, h;  // Dimensions
    SDL_Color color;  // Color of the character
public:
    Character(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color);
    void render();
    void moveCharacter(bool moveLeft, bool moveRight, bool moveUp, bool moveDown);
};

#endif
