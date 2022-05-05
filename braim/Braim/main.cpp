#include <iostream>
#include <memory>
#include <iomanip>
#include "graphics.h"
#include "guy.h"
#include "obstacle.h"
#include "world.h"
#include "slime.h"

using namespace std;
using namespace mssm;

#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif

// Note:  Mac Users who are using Qt Creator...
//        if the program compiles and runs but a window doesn't open up
//        try un-checking "run in terminal"


// Here are some of the basic drawing commands:

//void   line(Vec2d p1, Vec2d p2, Color c = WHITE);
//void   ellipse(Vec2d center, double w, double h, Color c = WHITE, Color f = TRANSPARENT);
//void   arc(Vec2d center, double w, double h, double a, double alen, Color c = WHITE);
//void   chord(Vec2d center, double w, double h, double a, double alen, Color c = WHITE, Color f = TRANSPARENT);
//void   pie(Vec2d center, double w, double h, double a, double alen, Color c = WHITE, Color f = TRANSPARENT);
//void   rect(Vec2d corner, double w, double h, Color c = WHITE, Color f = TRANSPARENT);
//void   polygon(std::vector<Vec2d> pts, Color border, Color fill = TRANSPARENT);
//void   polyline(std::vector<Vec2d> pts, Color color);
//void   text(Vec2d pos, double size, const std::string& str, Color textColor = WHITE, HAlign hAlign = HAlign::left, VAlign vAlign = VAlign::baseline);


/*
    Hamlin Notes:

    1. Pixel perfect integer math:   Draw some pictures, maybe on graph paper, defining
       _exactly_ what is meant by width, height, top, bottom, etc.  Make sure your
       helper methods like bottom/top/left/right follow those conventions.   For example,
       if left gives you position.x, which is "on" the rectangle then maybe right should
       give you position.x + width - 1 so that it gives you a location that is also "on"
       the rectangle.    Maybe change some of the helper functions so they return integer
       values instead of double.    The idea here is to be able to more clearly define
       what "touching" vs "overlapping" means, rather than adjusting that padding until
       you find something that hopefully works.    Ideally, touching would end up meaning
       exactly next to another object, with zero space between and zero overlap.

       Clearly defining things like this, and then making sure your code carefully matches
       those definitions will hopefully reduce confusion/ambiguity/weird bugs


       Maybe collision should then be defined (if it isn't already) as non-zero overlap.
       When a collision occurs, and you "shift" the mobile object to eliminate the overlap,
       make sure that you move it so that it is perfectly touching

    2. Right now, changing velocities and accelerations in response to collisions and contact
      feels a little too spread out throughout the code.  It would be easier to understand
      and debug if the reactions to collisions and contacts could be handled in fewer spots.
      Ideally, all the collisions and contact states could be figured out first, and then
      the rules could be applied for how those collisions and contacts affect the motion.

    3. brianObstacleCol and monsterObstacleCol share a lot of code. Maybe that can be
       refactored so the parts that differ between those two processes could be pulled out
       and abstracted, and the parts that are the same could become a single function.







*/


int main()
{
    Graphics g("MyProgram", 1024, 768);

    Camera c(g);

    Guy brian(6, 50, 50, {100,100});
    World world(&brian);
    world.obstacles.push_back(make_unique<Obstacle>(g.width(), 100, Vec2d{0, g.height()-100}));
    world.obstacles.push_back(make_unique<Obstacle>(100, 100, Vec2d{(g.width() - 100)/2, g.height()-200}));
    world.obstacles.push_back(make_unique<Obstacle>(100, 100, Vec2d{(g.width() - 100)/2 + 200, g.height()-200 - 100}));
    world.monsters.push_back(make_unique<Slime>(3, 25, 25, Vec2d{500, 100}));

    while (g.draw()) {

        c.offset = Vec2d{g.width()/2, 3*g.height()/5} - (brian.location);

        world.draw(c);
        world.update(c);

        g.cout << world.monsters[0]->velocity.x << endl;
        g.cout << world.monsters[0]->atEdgeL << endl;
        g.cout << world.monsters[0]->atEdgeR << endl;

        if (g.isKeyPressed(Key::ESC)) {
            break;
        }

        for (const Event& e : g.events()) {
            world.handleEvent(e);
            switch (e.evtType) {
            case EvtType::KeyPress:
                break;
            case EvtType::KeyRelease:
                break;
            case EvtType::MouseMove:
                break;
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            default:
                break;
            }
        }
    }

    return 0;
}




// TO DO ONE DAY
// ray class


