#include "guy.h"
using namespace mssm;
using namespace std;

Guy::Guy(int totalHealth, int width, int height, Vec2d location)
    :PhysicsObject(width, height, location), totalHealth{totalHealth}
{
    health = totalHealth;
}

void Guy::draw(Graphics &g)
{
    int barConstant = 50;
    //guy
    g.rect(location, width, height, PURPLE, PURPLE);
    //health bar
    g.rect({g.width() - health*barConstant - barConstant, barConstant}, health*barConstant, 20, BLACK, GREEN);
    g.rect({g.width() - health*barConstant - barConstant, barConstant}, totalHealth*barConstant, 20, BLACK);

    if(inContactB){
        g.rect({left(), bottom()}, width, 3, YELLOW, YELLOW);
    }
    if(inContactT){
        g.rect({left(), top()}, width, 3, YELLOW, YELLOW);
    }
    if(inContactL){
        g.rect({left(), top()}, 3, height, YELLOW, YELLOW);
    }
    if(inContactR){
        g.rect({right(), top()}, 3, height, YELLOW, YELLOW);
    }

    g.cout << "XVel: " << velocity.x << endl;
    g.cout << "YVel: " << velocity.y << endl;
    g.cout << "XAcc: " << acceleration.x << endl;
    g.cout << "YAcc: " << acceleration.y << endl;

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
        if(inContactB){
            acceleration.x = 0;
            velocity.x *= 0.85;
            if(abs(velocity.x) < 0.1){
                velocity.x = 0;
            }
        }
        else{
            acceleration.x = 0;
            velocity.x *= 0.97;
            if(abs(velocity.x) < 0.1){
                velocity.x = 0;
            }
        }
    }
    //jump is in event handler
    //no go above terminal velocity
    if(inContactB || velocity.y >= maxVelGrav ){
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

void Guy::topCollision()
{
    if(velocity.y <= 0){
        velocity.y = 0;
        inContactT = true;
    }
}

void Guy::bottomCollision()
{
    if(velocity.y >= 0){
        velocity.y = 0;
        inContactB = true;
    }
}

void Guy::leftCollision()
{
    if(velocity.x <= 0){
        velocity.x = 0;
        inContactL = true;
    }
}

void Guy::rightCollision()
{
    if(velocity.x >= 0){
        velocity.x = 0;
        inContactR = true;
    }
}
