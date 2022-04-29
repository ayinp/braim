#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "graphics.h"

class PhysicsObject
{
public:
    int width;
    int height;
    int gravity = 5;
    Vec2d velocity = {0, 0};
    Vec2d acceleration = {0, 0.05};
    Vec2d location;
public:
    PhysicsObject(int width, int height, Vec2d location);
    virtual void draw(mssm::Graphics& g) = 0;
    virtual void update(mssm::Graphics&);
};
#endif // PHYSICSOBJECT_H
