#ifndef WORLD_H
#define WORLD_H
#include <memory>
#include "guy.h"
#include "graphics.h"
#include "camera.h"

class World
{
public:
    std::vector<std::unique_ptr<PhysicsObject>> obstacles;
    std::vector<std::unique_ptr<PhysicsObject>> monsters;
    Guy* brian;
public:
    World(Guy* brian);
    void collisions();
    void draw(Camera& c);
    void update(Camera& c);
    void handleEvent(mssm::Event e);
    void brianObstacleCol(PhysicsObject* o);
    void brianMonsterCol(PhysicsObject* monsters);
    void monsterObstacleCol(PhysicsObject* obstacles, PhysicsObject* monsters);

};

#endif // WORLD_H
