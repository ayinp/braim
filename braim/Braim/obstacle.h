#ifndef GROUND_H
#define GROUND_H
#include "physicsobject.h"
#include "graphics.h"


class Obstacle : public PhysicsObject
{
public:

public:
    Obstacle(int width, int height, Vec2d location);
    virtual void draw(Camera& c) override;
    virtual void update(Camera& c) override;
};

#endif // GROUND_H
