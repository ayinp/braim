#include "world.h"
#include <iostream>
using namespace std;
using namespace mssm;



World::World(Guy* brian)
    :brian{brian}
{

}



//detect any collision -- done
//determine top/bottom or side by looking at overlap
//determine which side or top/bottom

void World::collisions(Graphics& g)
{
    for(int i = 0; i < objects.size(); i++){
        Vec2d oldAcc = brian->acceleration;
        if(brian->overlaps(*objects[i])){
            g.cout << "collides with: " << (long long)objects[i].get() << endl;
            double xOL = brian->xOverLap(*objects[i]);
            double yOL = brian->yOverLap(*objects[i]);
            //side collision
            if(xOL < yOL){
                //thing to right
                if(brian->velocity.x > 0){
                    brian->location.x = objects[i]->left() - brian->width;
                }
                //thing to left
                if(brian->velocity.x < 0){
                    brian->location.x = objects[i]->right();
                }
            }
            //top/bottom collision (or ==)
            else{
                //thing top
                if(brian->velocity.y < 0){
                    brian->location.y = objects[i]->bottom();
                }
                //thing bottom
                if(brian->velocity.y > 0){
                    brian->location.y = objects[i]->top() - brian->height;
                }
            }
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
    collisions(g);
}
