#ifndef WORLD_H
#define WORLD_H
#include <memory>
#include "guy.h"
#include "graphics.h"

class World
{
public:
    std::vector<std::unique_ptr<PhysicsObject>> objects;
    Guy* brian;
public:
    World(Guy* brian);
    void collisions(mssm::Graphics &g);
    void draw(mssm::Graphics& g);
    void update(mssm::Graphics& g);
};

#endif // WORLD_H
