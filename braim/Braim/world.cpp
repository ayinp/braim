#include "world.h"
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
        //thing to right
        if(brian->location.x >= objects[i]->location.x
                && (brian->location.y - brian->height) < objects[i]->location.y ){
            brian->velocity.x = 0;
        }
        //thing to left
        if(brian->location.x <= objects[i]->location.x + objects[i]->width
                && (brian->location.y - brian->height) < objects[i]->location.y ){
            brian->velocity.x = 0;
        }
        //thing above
        if(brian->location.y + brian->height >= objects[i]->location.y
                && (brian->location.x > objects[i]->location.x &&
                    brian->location.x - brian->width < objects[i]->location.x  + objects[i]->width)){
            brian->velocity.y = 0;
        }
        //thing below
        if(brian->location.y <= objects[i]->location.y + objects[i]->height
                && (brian->location.x > objects[i]->location.x &&
                    brian->location.x - brian->width < objects[i]->location.x  + objects[i]->width)){
            brian->velocity.y = 0;
        }
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
