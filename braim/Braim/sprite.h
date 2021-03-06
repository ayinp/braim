#ifndef SPRITE_H
#define SPRITE_H
#include "physicsobject.h"



class Sprite : public PhysicsObject
{
public:
    bool inContactB = false;
    bool inContactT = false;
    bool inContactR = false;
    bool inContactL = false;
    bool atEdgeL = false;
    bool atEdgeR = false;
public:
    Sprite(int width, int height, Vec2d location);
    virtual void topCollision();
    virtual void bottomCollision();
    virtual void leftCollision();
    virtual void rightCollision();
    bool overlaps(const PhysicsObject& other, int margin=0)const;
    int xOverLap(const PhysicsObject& other, int margin=0)const;
    int yOverLap(const PhysicsObject& other, int margin=0)const;
    void checkEdge(const PhysicsObject& other);
};

#endif // SPRITE_H
