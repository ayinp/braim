#ifndef SLIME_H
#define SLIME_H
#include "physicsObject.h"

class Slime : public PhysicsObject
{
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

#endif // SLIME_H
