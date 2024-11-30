#include "Character.hpp"
#include "Movement.hpp"

Character::Character(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color)
    : renderer(renderer), x(x), y(y), w(w), h(h), color(color) {
}

void Character::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);  // Set color
    SDL_Rect recto = { x, y, w, h };
    SDL_RenderFillRect(renderer, &recto);
}

void Character::moveCharacter(bool moveLeft, bool moveRight, bool moveUp, bool moveDown) {
    SDL_Rect recto = { x, y, w, h };
    move(recto, moveLeft, moveRight, moveUp, moveDown);
    x = recto.x;
    y = recto.y;
}
