#include "BallSticking.hpp"

BallSticking::BallSticking(const Vector2f &pos)
{
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::Cyan);
}

void BallSticking::Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    ball->SetSticking();
}

TYPE_BONUS BallSticking::GetType() const { return TYPE_BONUS::STICKY_BALL; }
