#include "ground.h"
using namespace mssm;
using namespace std;

Obstacle::Obstacle(int width, int height, Vec2d location)
    :PhysicsObject(width, height, location)
{

}

void Obstacle::draw(Camera &c)
{
    c.rect(location, width, height, {33,116,2}, {33,116,2});
}

void Obstacle::update(Camera &)
{

}
