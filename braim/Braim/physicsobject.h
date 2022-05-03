#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "graphics.h"
#include "camera.h"

class PhysicsObject
{
public:
    int width;
    int height;

    int maxVelGrav = 10;
    static double gravity;

    Vec2d velocity = {0, 0};
    Vec2d acceleration = {0, 0.1};
    Vec2d location;

    bool inContactB = false;
    bool inContactT = false;
    bool inContactR = false;
    bool inContactL = false;
public:
    PhysicsObject(int width, int height, Vec2d location);
    virtual void draw(Camera& c) = 0;
    virtual void update(Camera& c);

    double top()const{return location.y;};
    double bottom()const{return location.y+height;};
    double left()const{return location.x;};
    double right()const{return location.x+width;};

    bool overlaps(const PhysicsObject& other, double margin=0)const;
    double xOverLap(const PhysicsObject& other, double margin=0)const;
    double yOverLap(const PhysicsObject& other, double margin=0)const;
};
#endif // PHYSICSOBJECT_H
