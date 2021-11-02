#include "ChangeDirection.hpp"

ChangeDirection::ChangeDirection(const Vector2f &pos)
{
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::Blue);
}

void ChangeDirection::Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    ball->ChangeSpeed(COLLISION_TYPE::ANGLES);
}

TYPE_BONUS ChangeDirection::GetType() const { return TYPE_BONUS::CHANGE_DIRECTION; }
