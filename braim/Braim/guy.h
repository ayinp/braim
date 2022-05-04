#ifndef GUY_H
#define GUY_H
#include "graphics.h"
#include "sprite.h"



class Guy : public Sprite
{
public:
    int health;
    int totalHealth;
    int numJumps = 0;
public:
    Guy(int totalHealth, int width, int height, Vec2d location);
    virtual void draw(Camera& c) override;
    virtual void update(Camera& c) override;
    virtual void topCollision() override;
    virtual void bottomCollision() override;
    virtual void leftCollision() override;
    virtual void rightCollision() override;
    void handleEvent(mssm::Event e);
};

#endif // GUY_H
