#include "ground.h"
using namespace mssm;
using namespace std;

obstacle::obstacle(int width, int height, Vec2d location)
    :PhysicsObject(width, height, location)
{

}

void obstacle::draw(Camera &c)
{
    c.rect(location, width, height, {33,116,2}, {33,116,2});
}

void obstacle::update(Camera &)
{

}
