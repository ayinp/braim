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

