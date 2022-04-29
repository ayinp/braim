#ifndef GROUND_H
#define GROUND_H
#include "physicsobject.h"
#include "graphics.h"


class Ground : public PhysicsObject
{
public:

public:
    Ground(int width, int height, Vec2d location);
    virtual void draw(mssm::Graphics& g) override;
    virtual void update(mssm::Graphics& g) override;
};

#endif // GROUND_H
