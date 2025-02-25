#include <SDL2/SDL.h>
#include <iostream>
#include "IntersectionManager.h"

int main(int argc, char* argv[]) {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Intersection Simulation",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    IntersectionManager manager(WINDOW_WIDTH, WINDOW_HEIGHT);

    manager.addCar(std::make_unique<Car>(
        WINDOW_WIDTH / 2 - 10, -40.0f, 20, 40, 0.0f, 2.0f, SDL_Color{255, 0, 0, 255}));
    manager.addCar(std::make_unique<Car>(
        WINDOW_WIDTH / 2 - 10, static_cast<float>(WINDOW_HEIGHT),
        20, 40, 0.0f, -2.0f, SDL_Color{0, 255, 0, 255}));
    manager.addCar(std::make_unique<Car>(
        -40.0f, WINDOW_HEIGHT / 2 - 10, 40, 20, 3.0f, 0.0f, SDL_Color{0, 0, 255, 255}));
    manager.addCar(std::make_unique<Car>(
        static_cast<float>(WINDOW_WIDTH), WINDOW_HEIGHT / 2 - 10,
        40, 20, -2.0f, 0.0f, SDL_Color{255, 255, 0, 255}));

    manager.run();

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int regionHalf = 50;
        SDL_Rect regionRect = {
            WINDOW_WIDTH / 2 - regionHalf,
            WINDOW_HEIGHT / 2 - regionHalf,
            regionHalf * 2,
            regionHalf * 2
        };
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderDrawRect(renderer, &regionRect);

        manager.renderCars(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }

    manager.stop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
