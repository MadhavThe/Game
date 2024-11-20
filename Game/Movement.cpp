#include "Movement.hpp"
#include "Input.hpp"

void move(SDL_Rect& recto, bool moveLeft, bool moveRight, bool moveUp, bool moveDown) {
    if (moveLeft) recto.x -= 5;
    if (moveRight) recto.x += 5;
    if (moveUp) recto.y -= 5;
    if (moveDown) recto.y += 5;

    if (recto.x < 0) recto.x = 800 - recto.w;
    if (recto.x + recto.w > 800) recto.x = 0;
    if (recto.y < 0) recto.y = 600 - recto.h;
    if (recto.y + recto.h > 600) recto.y = 0;
}

void move1(SDL_Rect& rect1) {
    rect1.x += 5;
    rect1.y += 5;
    if (rect1.x + rect1.w > 800) rect1.x = 0;
    if (rect1.y + rect1.h > 600) rect1.y = 0;
}
