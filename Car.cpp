#include "Car.h"

Car::Car(float x_, float y_, int w, int h, float vx_, float vy_, SDL_Color color_)
    : x(x_), y(y_), width(w), height(h), vx(vx_), vy(vy_), color(color_), holdingLock(false) 
{
}

float Car::getX() const {
    return x;
}

float Car::getY() const {
    return y;
}

int Car::getWidth() const {
    return width;
}

int Car::getHeight() const {
    return height;
}

float Car::getVx() const {
    return vx;
}

float Car::getVy() const {
    return vy;
}

SDL_Color Car::getColor() const {
    return color;
}

bool Car::isHoldingLock() const {
    return holdingLock;
}

void Car::setHoldingLock(bool state) {
    holdingLock = state;
}

void Car::updatePosition() {
    x += vx;
    y += vy;
}

void Car::wrapPosition(int windowWidth, int windowHeight) {
    if (x < -width || x > windowWidth || y < -height || y > windowHeight) {
        if (vx > 0) x = -width;
        else if (vx < 0) x = static_cast<float>(windowWidth);
        if (vy > 0) y = -height;
        else if (vy < 0) y = static_cast<float>(windowHeight);
    }
}
