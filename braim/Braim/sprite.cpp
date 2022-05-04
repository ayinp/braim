#include "sprite.h"
using namespace std;

Sprite::Sprite(int width, int height, Vec2d location)
    :PhysicsObject(width, height, location)
{

}

void Sprite::topCollision()
{

}

void Sprite::bottomCollision()
{

}

void Sprite::leftCollision()
{

}

void Sprite::rightCollision()
{

}

bool Sprite::overlaps(const PhysicsObject &other, double margin) const
{
    if(right() + margin >= other.left() && left() - margin <= other.right() && bottom() + margin >= other.top() && top() - margin <= other.bottom()){
        return true;
    }
    return false;

}

double Sprite::xOverLap(const PhysicsObject &other, double margin) const
{
    return min(right()-margin, other.right()) - max(left()+margin, other.left());
}

double Sprite::yOverLap(const PhysicsObject &other, double margin) const
{
    return min(bottom()-margin, other.bottom()) - max(top()+margin, other.top());
}

void Sprite::checkEdge(const PhysicsObject& other)
{
    if(xOverLap(other) < width){
        if(location.x < other.location.x){
            atEdgeL = true;
        }
        else if(location.x > other.location.x){
            atEdgeR = true;
        }
        else{
            atEdgeL = false;
            atEdgeR = false;
        }


    }
}
