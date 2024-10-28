#include "SDL3/SDL_events.h"
#include "SDL3/SDL_keycode.h"
#include "stdio.h"
#include "SDL3/SDL_init.h"
#include "hello.hpp"

int main() {
    hello::say_hello();

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("failed to initialize sdl");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("sdl-template", 800, 600, 0);
    
    if (window == nullptr) {
        printf("failed to create window");
        return 1;
    }

    bool should_quit = false;
    SDL_Event e;

    while(!should_quit) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
                should_quit = true;
            }
        }
    }

    return 0;
}
