#ifndef CAR_H
#define CAR_H

#include <SDL2/SDL.h>

class Car {
public:
    Car(float x_, float y_, int w, int h, float vx_, float vy_, SDL_Color color_);
    float getX() const;
    float getY() const;
    int getWidth() const;
    int getHeight() const;
    float getVx() const;
    float getVy() const;
    SDL_Color getColor() const;
    bool isHoldingLock() const;
    void setHoldingLock(bool state);
    void updatePosition();
    void wrapPosition(int windowWidth, int windowHeight);

private:
    float x;
    float y;
    int width;
    int height;
    float vx;
    float vy;
    SDL_Color color;
    bool holdingLock;
};

#endif
