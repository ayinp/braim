#ifndef GUY_H
#define GUY_H
#include "graphics.h"
#include "physicsobject.h"



class Guy : public PhysicsObject{
public:
    int health;
    int totalHealth;
    int numJumps = 0;
    bool inContactB = false;
    bool inContactT = false;
    bool inContactR = false;
    bool inContactL = false;
public:
    Guy(int totalHealth, int width, int height, Vec2d location);
    virtual void draw(mssm::Graphics& g) override;
    virtual void update(mssm::Graphics& g) override;
    void handleEvent(mssm::Event e);
    void topCollision();
    void bottomCollision();
    void leftCollision();
    void rightCollision();
};

#endif // GUY_H
