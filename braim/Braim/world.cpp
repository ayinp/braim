#include "world.h"
#include <iostream>
using namespace std;
using namespace mssm;



World::World(Guy* brian)
    :brian{brian}
{

}

void World::collisions()
{
    //make this better oneday
    for(int i = 0; i < objects.size(); i++){
        Vec2d oldAcc = brian->acceleration;
        //thing to right
        if(brian->location.x + brian->width > objects[i]->location.x

                && brian->location.y + brian->height <= objects[i]->location.y
                && brian->location.y >= objects[i]->location.y + objects[i]->height){

            cout << brian->location.x + brian->width << "  " << objects[i]->location.x << endl;
            brian->velocity.x = -(brian->velocity.x);
            brian->acceleration.x = -0.1;
        }
        //thing to left
        if(brian->location.x < objects[i]->location.x + objects[i]->width
                && brian->location.y - brian->height >= objects[i]->location.y
                && brian->location.y <= objects[i]->location.y - objects[i]->height){
            brian->velocity.x = -0.5*(brian->velocity.x);
            brian->acceleration.x = -0.1;
        }
        //thing below
        if(brian->location.y + brian->height > objects[i]->location.y
                && brian->location.x <= objects[i]->location.x + objects[i]->width
                && brian->location.x + brian->width >= objects[i]->location.x){
            brian->velocity.y = -0.5*(brian->velocity.y);
            brian->acceleration.y = -0.1;
        }
        brian->acceleration = oldAcc;
    }
}

void World::draw(Graphics &g)
{
    brian->draw(g);
    for(int i = 0; i < objects.size(); i++){
        objects[i]->draw(g);
    }
}

void World::update(Graphics &g)
{
    brian->update(g);
    for(int i = 0; i < objects.size(); i++){
        objects[i]->update(g);
    }
    collisions();
}
