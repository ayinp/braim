#ifndef GUY_H
#define GUY_H
#include "graphics.h"
#include "physicsobject.h"



class Guy : public PhysicsObject{
public:
    int health;
public:
    Guy(int health, int width, int height, Vec2d location);
    virtual void draw(mssm::Graphics& g) override;
    virtual void update(mssm::Graphics& g) override;
};

#endif // GUY_H
