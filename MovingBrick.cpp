#include "MovingBrick.hpp"

MovingBrick::MovingBrick(const Vector2f &pos)
{
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::Green);
}

void MovingBrick::Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    field->CreateMovingBrick();
}

TYPE_BONUS MovingBrick::GetType() const { return TYPE_BONUS::MOVING_BRICK; }
