#include "ground.h"
using namespace mssm;
using namespace std;

Ground::Ground(int width, int height, Vec2d location)
    :PhysicsObject(width, height, location)
{

}

void Ground::draw(Graphics &g)
{
    g.rect(location, width, height, GREEN, GREEN);
}

void Ground::update(Graphics &g)
{

}
