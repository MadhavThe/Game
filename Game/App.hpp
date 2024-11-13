#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>

class App {
public:
    App();
    ~App();
    bool init();
    void cleanup();
    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
