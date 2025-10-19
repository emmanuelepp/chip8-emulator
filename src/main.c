#include <stdio.h>
#include <SDL3/SDL.h>
#include <chip8.h>

int main(int argc, char **argv)
{
    // Window & renderer setup
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, 0);

    if (!window)
        return 1;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
        return 1;

    while (1)
    {
        // Events: handle all pending system events; exit main loop on window close.
        SDL_Event event;
        while (SDL_PollEvent(&event))
            if (event.type == SDL_EVENT_QUIT)
                goto out;

        // Frame: clear backbuffer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw: outline 40x40 rect at (0,0) in white (SDL_FRect).
        // Note: SDL3 render APIs use float rectangles (SDL_FRect).
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_FRect r = {0.f, 0.f, 40.f, 40.f};
        SDL_RenderRect(renderer, &r);

        SDL_RenderPresent(renderer);
        // SDL_Delay(16); // optional: avoid 100% CPU
    }

out:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}