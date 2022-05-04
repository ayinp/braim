#ifndef SLIME_H
#define SLIME_H
#include "Sprite.h"

class Slime : public Sprite {
public:
    int totalHealth;
    int health;
public:
    Slime(int totalHealth, int width, int height, Vec2d location);
    virtual void draw(Camera& c) override;
    virtual void update(Camera& c) override;
    virtual void topCollision() override;
    virtual void bottomCollision() override;
    virtual void leftCollision() override;
    virtual void rightCollision() override;
};

//if overlap < slime width he is over the edge

#endif // SLIME_H
