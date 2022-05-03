#include "physicsobject.h"
using namespace std;

double PhysicsObject::gravity = 0.5;

PhysicsObject::PhysicsObject(int width, int height, Vec2d location)
    :width{width}, height{height}, location{location}
{

}

void PhysicsObject::update(Camera & /*c*/)
{
    location = location + velocity;
    velocity = velocity + acceleration;
    if(velocity.y >= maxVelGrav ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = 0.05;
    }
}

bool PhysicsObject::overlaps(const PhysicsObject &other, double margin) const
{
    if(right() + margin >= other.left() && left() - margin <= other.right() && bottom() + margin >= other.top() && top() - margin <= other.bottom()){
        return true;
    }
    return false;

}

double PhysicsObject::xOverLap(const PhysicsObject &other, double margin) const
{
    return min(right()-margin, other.right()) - max(left()+margin, other.left());
}

double PhysicsObject::yOverLap(const PhysicsObject &other, double margin) const
{
    return min(bottom()-margin, other.bottom()) - max(top()+margin, other.top());
}
