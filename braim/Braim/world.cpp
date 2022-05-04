#include "world.h"
#include <iostream>
#include <memory>
#include "obstacle.h"
#include "slime.h"
#include "guy.h"
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
    //check if brian collides with obstacles
    brian->inContactB = false;
    brian->inContactT = false;
    brian->inContactR = false;
    brian->inContactL = false;
    for(int i = 0; i < obstacles.size(); i++){
        brianObstacleCol(obstacles[i].get());
    }

    // check if brian collides with monsters
    for(int i = 0; i < obstacles.size(); i++){
        brianMonsterCol(monsters[i].get());
    }

    // check if monsters collide with obstacles
    for(int m = 0; m < monsters.size(); m++){
        monsters[m]->inContactB = false;
        monsters[m]->inContactT = false;
        monsters[m]->inContactR = false;
        monsters[m]->inContactL = false;
        for(int o = 0; o < obstacles.size(); o++){
            monsterObstacleCol(obstacles[o].get(), monsters[m].get());
        }
    }

    if(brian->inContactB){
        brian->numJumps = 0;
    }

}

void World::draw(Camera& c)
{
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i]->draw(c);
    }
    for(int i = 0; i < monsters.size(); i++){
        monsters[i]->draw(c);
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
    for(int i = 0; i < monsters.size(); i++){
        monsters[i]->update(c);
    }
}

void World::handleEvent(Event e)
{
    brian->handleEvent(e);
}

void World::brianObstacleCol(PhysicsObject* o)
{
    if(brian->overlaps(*o)){
        double xOL = brian->xOverLap(*o);
        double yOL = brian->yOverLap(*o);
        //side collision
        if(xOL < yOL){
            //thing to right
            if(brian->location.x < o->location.x){
                brian->location.x = o->left() - brian->width - 1;
                brian->velocity.x = 0;
                brian->inContactR = true;
            }
            //thing to left
            if(brian->location.x > o->location.x){
                brian->location.x = o->right() + 1;
                brian->inContactL = true;
                brian->velocity.x = 0;
            }
        }
        //bottom collision (or ==)
        else{
            //thing bottom
            if(brian->location.y < o->location.y){
                brian->velocity.y = 0;
                brian->location.y = o->top() - brian->height - 1;
                brian->inContactB = true;
            }
            //thing top
            else if(brian->location.y > o->location.y){
                brian->velocity.y = 0;
                brian->location.y = o->bottom() + 1;
                brian->inContactT = true;
            }
        }
    }
    //contact
    else if(brian->overlaps(*o, 1.1)){

        double xOL = brian->xOverLap(*o);
        double yOL = brian->yOverLap(*o);
        //bottom or top collision
        if(xOL > yOL){
            if(brian->location.y < o->location.y){
                brian->bottomCollision();

            }
            else if(brian->location.y > o->location.y){
                brian->topCollision();
            }

        }
        //left or right collision (or ==)
        else{
            //thing to right
            if(brian->location.x < o->location.x){
                brian->rightCollision();
            }
            //thing to left
            if(brian->location.x > o->location.x){
                brian->leftCollision();
            }

        }
    }


}

void World::brianMonsterCol(PhysicsObject *monster)
{

}

void World::monsterObstacleCol(PhysicsObject *o, Sprite *m)
{
    if(m->overlaps(*o)){
        double xOL = m->xOverLap(*o);
        double yOL = m->yOverLap(*o);
        //side collision
        if(xOL < yOL){
            //thing to right
            if(m->location.x < o->location.x){
                m->location.x = o->left() - m->width - 1;
                m->inContactR = true;
            }
            //thing to left
            if(m->location.x > o->location.x){
                m->location.x = o->right() + 1;
                m->inContactL = true;
            }
        }
        //bottom collision (or ==)
        else{
            //thing bottom
            if(m->location.y < o->location.y){
                m->velocity.y = 0;
                m->location.y = o->top() - m->height - 1;
                m->inContactB = true;
            }
            //thing top
            else if(m->location.y > o->location.y){
                m->velocity.y = 0;
                m->location.y = o->bottom() + 1;
                m->inContactT = true;
            }
        }
    }
    //contact
    else if(m->overlaps(*o, 1.1)){

        double xOL = m->xOverLap(*o);
        double yOL = m->yOverLap(*o);
        //bottom or top collision
        if(xOL > yOL){
            if(m->location.y < o->location.y){
                m->bottomCollision();
                m->checkEdge(*o);
            }
            else if(m->location.y > o->location.y){
                m->topCollision();
            }

        }
        //left or right collision (or ==)
        else{
            //thing to right
            if(m->location.x < o->location.x){
                m->rightCollision();
            }
            //thing to left
            if(m->location.x > o->location.x){
                m->leftCollision();
            }

        }
    }
}
