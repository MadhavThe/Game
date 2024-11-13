#include "Movement.hpp"

void move(SDL_Rect& rect, bool moveLeft, bool moveRight, bool moveUp, bool moveDown) {
    if (moveLeft) rect.x -= 5;
    if (moveRight) rect.x += 5;
    if (moveUp) rect.y -= 5;
    if (moveDown) rect.y += 5;

    if (rect.x < 0) rect.x = 800 - rect.w;
    if (rect.x + rect.w > 800) rect.x = 0;
    if (rect.y < 0) rect.y = 600 - rect.h;
    if (rect.y + rect.h > 600) rect.y = 0;
}

void move1(SDL_Rect& rect1) {
    rect1.x += 5;
    rect1.y += 5;
    if (rect1.x + rect1.w > 800) rect1.x = 0;
    if (rect1.y + rect1.h > 600) rect1.y = 0;
}
