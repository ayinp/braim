#ifndef GROUND_H
#define GROUND_H
#include "physicsobject.h"
#include "graphics.h"


class obstacle : public PhysicsObject
{
public:

public:
    obstacle(int width, int height, Vec2d location);
    virtual void draw(Camera &c) override;
    virtual void update(Camera &) override;
};

#endif // GROUND_H
