#ifndef GUY_H
#define GUY_H
#include "graphics.h"
#include "physicsobject.h"



class Guy : public PhysicsObject{
public:
    int health;
    int totalHealth;
    int numJumps = 0;
public:
    Guy(int totalHealth, int width, int height, Vec2d location);
    virtual void draw(Camera& c) override;
    virtual void update(Camera& c) override;
    void handleEvent(mssm::Event e);
    void topCollision();
    void bottomCollision();
    void leftCollision();
    void rightCollision();
};

#endif // GUY_H
