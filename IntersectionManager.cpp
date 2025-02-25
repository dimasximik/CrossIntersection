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
    while (!stopFlag.load()) {
        bool needLock = false;
        if ((car->getVx() > 0 && car->getX() + car->getWidth() + car->getVx() >= regionLeft) ||
            (car->getVx() < 0 && car->getX() + car->getVx() <= regionRight)) {
            needLock = true;
        }
        if ((car->getVy() > 0 && car->getY() + car->getHeight() + car->getVy() >= regionTop) ||
            (car->getVy() < 0 && car->getY() + car->getVy() <= regionBottom)) {
            needLock = true;
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
            bool leftSidePassed  = (car->getVx() < 0 && car->getX() + car->getWidth() < regionLeft);
            bool rightSidePassed = (car->getVx() > 0 && car->getX() > regionRight);
            bool topSidePassed   = (car->getVy() < 0 && car->getY() + car->getHeight() < regionTop);
            bool bottomSidePassed= (car->getVy() > 0 && car->getY() > regionBottom);

            if (leftSidePassed || rightSidePassed || topSidePassed || bottomSidePassed) {
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
