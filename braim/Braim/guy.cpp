#include "guy.h"
using namespace mssm;
using namespace std;

Guy::Guy(int health, int width, int height, Vec2d location)
    :PhysicsObject(width, height, location), health{health}
{

}

void Guy::draw(Graphics &g)
{
    g.rect(location, width, height, PURPLE, PURPLE);

}

void Guy::update(Graphics &g)
{
    //right movement
    if(g.isKeyPressed(Key::Right) || g.isKeyPressed('D')) {
        acceleration.x = 0.3;
        if(velocity.x >= 5){
            acceleration.x = 0;
            velocity.x = 5;
        }
    }
    //left movement
    else if(g.isKeyPressed(Key::Left) || g.isKeyPressed('A')){
        acceleration.x = -0.3;
        if(velocity.x <= -5){
            acceleration.x = 0;
            velocity.x = -5;
        }
    }
    //no input left or rihgt
    else{
        acceleration.x = 0;
        velocity.x *= 0.85;
        if(abs(velocity.x) < 1){
            velocity.x = 0;
        }
    }
    //jump is in event handler
    //no go above terminal velocity
    if(isOnGround || velocity.y >= maxVelGrav ){
        acceleration.y = 0;
    }
    else{
        acceleration.y = gravity;
    }
    location = location + velocity;
    velocity = velocity + acceleration;
}

void Guy::handleEvent(Event e)
{
    switch (e.evtType) {
    case EvtType::KeyPress:
        //jump
        if(e.arg == ' ' && numJumps < 2){
            velocity.y = -4.5;
            numJumps++;
            //jumps are set back to 0 if land on ground in collisions method on world)

        }
        break;
    case EvtType::KeyRelease:
        break;
    case EvtType::MouseMove:
        break;
    case EvtType::MousePress:
        break;
    case EvtType::MouseRelease:
        break;
    default:
        break;
    }
}
