#include "guy.h"
using namespace mssm;
using namespace std;

Guy::Guy(int health, int width, int height, Vec2d location)
    :PhysicsObject(width, height, location), health{health}
{

}

void Guy::draw(Graphics &g)
{
    g.ellipse(location, width, height, PURPLE, PURPLE);
}

void Guy::update(Graphics &g)
{
    if(g.isKeyPressed(Key::Right) || g.isKeyPressed('D')) {
        velocity.x = 5;
    }
    else if(g.isKeyPressed(Key::Left) || g.isKeyPressed('A')){
        velocity.x = -5;
    }
    else{
        velocity.x = 0;
    }
    if(velocity.y >= gravity ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = 0.05;
    }
    location = location + velocity;
    velocity = velocity + acceleration;
}