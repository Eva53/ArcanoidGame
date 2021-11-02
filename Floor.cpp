#include "Floor.hpp"

Floor::Floor(const Vector2f &pos)
{
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::Red);
}

void Floor::Create(shared_ptr<Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    ball->SetFloor(true);
}

TYPE_BONUS Floor::GetType() const { return TYPE_BONUS::SET_BOTTOM; }
