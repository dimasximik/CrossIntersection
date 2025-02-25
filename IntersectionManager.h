#ifndef INTERSECTION_MANAGER_H
#define INTERSECTION_MANAGER_H

#include <vector>
#include <memory>
#include <atomic>
#include <mutex>
#include <thread>
#include <SDL2/SDL.h>
#include "Car.h"

class IntersectionManager {
public:
    IntersectionManager(int windowWidth, int windowHeight);
    ~IntersectionManager();
    void addCar(std::unique_ptr<Car> car);
    void run();
    void stop();
    void renderCars(SDL_Renderer* renderer);

private:
    void carThread(Car* car);
    std::vector<std::unique_ptr<Car>> cars;
    std::vector<std::thread> threads;
    std::atomic<bool> stopFlag;
    std::mutex intersectionMutex;
    std::mutex posMutex;
    int windowWidth;
    int windowHeight;
    int regionLeft;
    int regionRight;
    int regionTop;
    int regionBottom;
};

#endif
