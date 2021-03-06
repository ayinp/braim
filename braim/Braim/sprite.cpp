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

bool Sprite::overlaps(const PhysicsObject &other, int margin) const
{
    if(right() + margin >= other.left() && left() - margin <= other.right() && bottom() + margin >= other.top() && top() - margin <= other.bottom()){
        return true;
    }
    return false;

}

int Sprite::xOverLap(const PhysicsObject &other, int margin) const
{
    return min(right()-margin, other.right()) - max(left()+margin, other.left());
}

int Sprite::yOverLap(const PhysicsObject &other, int margin) const
{
    return min(bottom()-margin, other.bottom()) - max(top()+margin, other.top());
}

void Sprite::checkEdge(const PhysicsObject& other)
{
    if(xOverLap(other) < width-0.001){
        if(location.x < other.location.x){
            atEdgeL = true;
        }
        else if(location.x > other.location.x){
            atEdgeR = true;
        }
    }
}
