#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>

class Input {
public:
    void handleInput(bool& isRunning, bool& moveLeft, bool& moveRight, bool& moveUp, bool& moveDown);
};

#endif
