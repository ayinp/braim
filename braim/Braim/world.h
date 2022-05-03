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
//    std::vector<std::unique_ptr<PhysicsObject>> monsters;
//    std::vector<PhysicsObject*> onScreen;
//    std::vector<PhysicsObject*> monstersOnScreen;
//    std::vector<PhysicsObject*> obstaclesOnScreen;
    Guy* brian;
public:
    World(Guy* brian);
    void collisions();
    void draw(Camera& c);
    void update(Camera& c);
    void handleEvent(mssm::Event e);

};

#endif // WORLD_H
