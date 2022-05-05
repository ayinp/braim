#include "slime.h"
#include <iomanip>
#include <iostream>
using namespace mssm;
using namespace std;

Slime::Slime(int totalHealth, int width, int height, Vec2d location)
    :Sprite(width, height, location), totalHealth{totalHealth}
{
    velocity.x = randomTrue(0.5) ? randomDouble(1, 3) : randomDouble(-3, -1);
}

void Slime::draw(Camera &c)
{
    c.rect(location, width, height, YELLOW, YELLOW);
    if(inContactB){
        c.rect({left(), bottom()}, width, 3, RED, RED);
    }
    if(inContactT){
        c.rect({left(), top()}, width, 3, RED, RED);
    }
    if(inContactL){
        c.rect({left(), top()}, 3, height, RED, RED);
    }
    if(inContactR){
        c.rect({right(), top()}, 3, height, RED, RED);
    }
}

void Slime::update(Camera &c)
{
    if(inContactB || velocity.y >= maxVelGrav ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = gravity;
    }

    if(atEdgeL){
        velocity.x = std::abs(velocity.x);
    }
    else if(atEdgeR){
        velocity.x = -std::abs(velocity.x);
    }
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

    cout << "wall" << endl;
    velocity.x = std::abs(velocity.x);
    inContactL = true;
}

void Slime::rightCollision()
{
    cout << "wall" << endl;
    velocity.x = -std::abs(velocity.x);
    inContactR = true;

}

