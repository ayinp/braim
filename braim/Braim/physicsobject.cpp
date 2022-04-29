#include "physicsobject.h"

PhysicsObject::PhysicsObject(int width, int height, Vec2d location)
    :width{width}, height{height}, location{location}
{

}

void PhysicsObject::update(mssm::Graphics& /*g*/)
{
    location = location + velocity;
    velocity = velocity + acceleration;
    if(velocity.y >= gravity ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = 0.05;
    }
}
