#include "IntersectionManager.h"
#include <chrono>

IntersectionManager::IntersectionManager(int w, int h)
    : stopFlag(false), windowWidth(w), windowHeight(h)
{
    int regionHalf = 50;
    regionLeft   = windowWidth / 2 - regionHalf;
    regionRight  = windowWidth / 2 + regionHalf;
    regionTop    = windowHeight / 2 - regionHalf;
    regionBottom = windowHeight / 2 + regionHalf;
}

IntersectionManager::~IntersectionManager() {
    stop();
}

void IntersectionManager::addCar(std::unique_ptr<Car> car) {
    cars.push_back(std::move(car));
}

void IntersectionManager::run() {
    for (auto& c : cars) {
        threads.emplace_back(&IntersectionManager::carThread, this, c.get());
    }
}

void IntersectionManager::stop() {
    stopFlag.store(true);
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
    threads.clear();
}

void IntersectionManager::renderCars(SDL_Renderer* renderer) {
    std::lock_guard<std::mutex> lock(posMutex);
    for (auto& c : cars) {
        SDL_SetRenderDrawColor(renderer, c->getColor().r, c->getColor().g, c->getColor().b, c->getColor().a);
        SDL_Rect carRect = { static_cast<int>(c->getX()), static_cast<int>(c->getY()),
                             c->getWidth(), c->getHeight() };
        SDL_RenderFillRect(renderer, &carRect);
    }
}

void IntersectionManager::carThread(Car* car) {
    SDL_Rect intersectionRect {
        regionLeft,
        regionTop,
        regionRight - regionLeft,
        regionBottom - regionTop
    };

    while (!stopFlag.load()) {
        bool needLock;
        {
            float nextX = car->getX() + car->getVx();
            float nextY = car->getY() + car->getVy();

            SDL_Rect nextCarRect {
                static_cast<int>(nextX),
                static_cast<int>(nextY),
                car->getWidth(),
                car->getHeight()
            };

            needLock = (SDL_HasIntersection(&nextCarRect, &intersectionRect) == SDL_TRUE);
        }

        if (!car->isHoldingLock() && needLock) {
            intersectionMutex.lock();
            car->setHoldingLock(true);
        }

        {
            std::lock_guard<std::mutex> lock(posMutex);
            car->updatePosition();
        }

        if (car->isHoldingLock()) {
            SDL_Rect currentCarRect {
                static_cast<int>(car->getX()),
                static_cast<int>(car->getY()),
                car->getWidth(),
                car->getHeight()
            };

            bool inIntersection = (SDL_HasIntersection(&currentCarRect, &intersectionRect) == SDL_TRUE);
            if (!inIntersection) {
                car->setHoldingLock(false);
                intersectionMutex.unlock();
            }
        }

        car->wrapPosition(windowWidth, windowHeight);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    if (car->isHoldingLock()) {
        intersectionMutex.unlock();
    }
}

