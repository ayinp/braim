#include "slime.h"
using namespace mssm;

Slime::Slime(int totalHealth, int width, int height, Vec2d location)
    :PhysicsObject(width, height, location), totalHealth{totalHealth}
{

}

void Slime::draw(Camera &c)
{
    c.rect(location, width, height, YELLOW, YELLOW);
}

void Slime::update(Camera &c)
{
    if(inContactB || velocity.y >= maxVelGrav ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = gravity;
    }
    velocity.x = 2;
    location = location + velocity;
    velocity = velocity + acceleration;
}

void Slime::topCollision()
{
    if(velocity.y <= 0){
        velocity.y = 0;
        inContactT = true;
    }
}

void Slime::bottomCollision()
{
    if(velocity.y >= 0){
        velocity.y = 0;
        inContactB = true;
    }
}

void Slime::leftCollision()
{

    velocity.x = -velocity.x;
    inContactL = true;
}

void Slime::rightCollision()
{
    velocity.x = -velocity.x;
    inContactR = true;

}
