#include "world.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace mssm;

#pragma GCC diagnostic ignored "-Wsign-compare"

World::World(Guy* brian)
    :brian{brian}
{

}


// eventually have seperate vector for things actively on screen or near being on screen and only draw/do collision math for them
// will have to store last location before stopping drawing and math so can be redrawn if closer
// decide if theyre in the draw and calculate vector by looking at their last/starting location and seeing if any of them will be on screen

void World::collisions()
{
    //check if brian collides with anything
    brian->inContactB = false;
    brian->inContactT = false;
    brian->inContactR = false;
    brian->inContactL = false;
    for(int i = 0; i < obstacles.size(); i++){
        if(brian->overlaps(*obstacles[i])){
            double xOL = brian->xOverLap(*obstacles[i]);
            double yOL = brian->yOverLap(*obstacles[i]);
            //side collision
            if(xOL < yOL){
                //thing to right
                if(brian->location.x < obstacles[i]->location.x){
                    brian->location.x = obstacles[i]->left() - brian->width - 1;
                    brian->velocity.x = 0;
                    brian->inContactR = true;
                }
                //thing to left
                if(brian->location.x > obstacles[i]->location.x){
                    brian->location.x = obstacles[i]->right() + 1;
                    brian->inContactL = true;
                    brian->velocity.x = 0;
                }
            }
            //bottom collision (or ==)
            else{
                //thing bottom
                if(brian->location.y < obstacles[i]->location.y){
                    brian->velocity.y = 0;
                    brian->location.y = obstacles[i]->top() - brian->height - 1;
                    brian->inContactB = true;
                }
                //thing top
                else if(brian->location.y > obstacles[i]->location.y){
                    brian->velocity.y = 0;
                    brian->location.y = obstacles[i]->bottom() + 1;
                    brian->inContactT = true;
                }
            }
        }
        //contact
        else if(brian->overlaps(*obstacles[i], 1.1)){

            double xOL = brian->xOverLap(*obstacles[i]);
            double yOL = brian->yOverLap(*obstacles[i]);
            //bottom or top collision
            if(xOL > yOL){
                if(brian->location.y < obstacles[i]->location.y){
                    brian->bottomCollision();

                }
                else if(brian->location.y > obstacles[i]->location.y){
                    brian->topCollision();
                }

            }
            //left or right collision (or ==)
            else{
                //thing to right
                if(brian->location.x < obstacles[i]->location.x){
                    brian->rightCollision();
                }
                //thing to left
                if(brian->location.x > obstacles[i]->location.x){
                    brian->leftCollision();
                }

            }
        }

    }
    if(brian->inContactB){
        brian->numJumps = 0;
    }

    // check if any monsters collide with anything

}

void World::draw(Camera& c)
{
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i]->draw(c);
    }
    brian->draw(c);
}

void World::update(Camera& c)
{
    // call method to check whats onscreen and update the onscreen vectors
    collisions();
    brian->update(c);
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i]->update(c);
    }
}

void World::handleEvent(Event e)
{
    brian->handleEvent(e);
}
