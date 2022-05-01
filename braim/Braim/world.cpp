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
    bool inContact = false;
    for(int i = 0; i < objects.size(); i++){
        if(brian->overlaps(*objects[i])){
            g.cout << "Overlap" << endl;
            double xOL = brian->xOverLap(*objects[i]);
            double yOL = brian->yOverLap(*objects[i]);
            //side collision
            if(xOL < yOL){
                //thing to right
                if(brian->velocity.x > 0){
                    //  g.cerr << "Thing to right" << endl;
                    brian->location.x = objects[i]->left() - brian->width - 1;
                }
                //thing to left
                if(brian->velocity.x < 0){
                    brian->location.x = objects[i]->right() + 1;
                }
            }
            //bottom collision (or ==)
            else{
                //thing bottom
                if(brian->velocity.y > 0){
                    brian->velocity.y = 0;
                    brian->location.y = objects[i]->top() - brian->height - 1;
                    inContact = true;
                }
            }
        }
        else if(brian->overlaps(*objects[i], 1.1)){

            double xOL = brian->xOverLap(*objects[i]);
            double yOL = brian->yOverLap(*objects[i]);
            //bottom collision (or ==)
            if(xOL > yOL){
                if(brian->velocity.y >= 0){
                    brian->velocity.y = 0;
                    inContact = true;

                }
            }
        }

    }
    brian->isOnGround = inContact;
    if(brian->isOnGround){
        brian->numJumps = 0;
    }

    g.cout << (brian->isOnGround ? "OnGround" : "Not on ground") << endl;
    g.cout << "XVel: " << brian->velocity.x << endl;
    g.cout << "YVel: " << brian->velocity.y << endl;

}

void World::draw(Graphics &g)
{
    for(int i = 0; i < objects.size(); i++){
        objects[i]->draw(g);
    }
    brian->draw(g);
}

void World::update(Graphics &g)
{
    collisions(g);
    brian->update(g);
    for(int i = 0; i < objects.size(); i++){
        objects[i]->update(g);
    }
}

void World::handleEvent(Event e)
{
    brian->handleEvent(e);
}
