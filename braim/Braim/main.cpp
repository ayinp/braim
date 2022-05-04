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


