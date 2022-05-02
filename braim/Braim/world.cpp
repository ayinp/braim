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

void World::collisions()
{
    brian->inContactB = false;
    brian->inContactT = false;
    brian->inContactR = false;
    brian->inContactL = false;
    for(int i = 0; i < objects.size(); i++){
        if(brian->overlaps(*objects[i])){
            double xOL = brian->xOverLap(*objects[i]);
            double yOL = brian->yOverLap(*objects[i]);
            //side collision
            if(xOL < yOL){
                //thing to right
                if(brian->location.x < objects[i]->location.x){
                    brian->location.x = objects[i]->left() - brian->width - 1;
                    brian->velocity.x = 0;
                    brian->inContactR = true;
                }
                //thing to left
                if(brian->location.x > objects[i]->location.x){
                    brian->location.x = objects[i]->right() + 1;
                    brian->inContactL = true;
                    brian->velocity.x = 0;
                }
            }
            //bottom collision (or ==)
            else{
                //thing bottom
                if(brian->location.y < objects[i]->location.y){
                    brian->velocity.y = 0;
                    brian->location.y = objects[i]->top() - brian->height - 1;
                    brian->inContactB = true;
                }
                //thing top
                else if(brian->location.y > objects[i]->location.y){
                    brian->velocity.y = 0;
                    brian->location.y = objects[i]->bottom() + 1;
                    brian->inContactT = true;
                }
            }
        }
        //contact
        else if(brian->overlaps(*objects[i], 1.1)){

            double xOL = brian->xOverLap(*objects[i]);
            double yOL = brian->yOverLap(*objects[i]);
            //bottom or top collision
            if(xOL > yOL){
                if(brian->location.y < objects[i]->location.y){
                    brian->bottomCollision();

                }
                else if(brian->location.y > objects[i]->location.y){
                    brian->topCollision();
                }

            }
            //left or right collision (or ==)
            else{
                //thing to right
                if(brian->location.x < objects[i]->location.x){
                    brian->rightCollision();
                }
                //thing to left
                if(brian->location.x > objects[i]->location.x){
                    brian->leftCollision();
                }

            }
        }

    }
    if(brian->inContactB){
        brian->numJumps = 0;
    }

}

void World::draw(Camera& c)
{
    for(int i = 0; i < objects.size(); i++){
        objects[i]->draw(c);
    }
    brian->draw(c);
}

void World::update(Camera& c)
{
    collisions();
    brian->update(c);
    for(int i = 0; i < objects.size(); i++){
        objects[i]->update(c);
    }
}

void World::handleEvent(Event e)
{
    brian->handleEvent(e);
}
