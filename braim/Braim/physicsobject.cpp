#include "physicsobject.h"
using namespace std;

double PhysicsObject::gravity = 0.1;

PhysicsObject::PhysicsObject(int width, int height, Vec2d location)
    :width{width}, height{height}, location{location}
{

}

void PhysicsObject::update(mssm::Graphics& /*g*/)
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

bool PhysicsObject::overlaps(const PhysicsObject &other) const
{
    if(right() > other.left() && left() < other.right() && bottom() > other.top() && top() < other.bottom()){
        return true;
    }
    return false;

}

double PhysicsObject::xOverLap(const PhysicsObject &other) const
{
    return min(right(), other.right()) - max(left(), other.left());
}

double PhysicsObject::yOverLap(const PhysicsObject &other) const
{
    return min(bottom(), other.bottom()) - max(top(), other.top());
}
