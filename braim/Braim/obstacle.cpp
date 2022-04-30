#include "ground.h"
using namespace mssm;
using namespace std;

obstacle::obstacle(int width, int height, Vec2d location)
    :PhysicsObject(width, height, location)
{

}

void obstacle::draw(Graphics &g)
{
    g.rect(location, width, height, GREEN, GREEN);
    g.ellipse(location, 5, 5, BLUE, BLUE);
}

void obstacle::update(Graphics&)
{

}
