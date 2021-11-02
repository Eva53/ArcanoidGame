#include "ChangeSpeedBall.hpp"

ChangeSpeedBall::ChangeSpeedBall(const Vector2f &pos)
{
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::Yellow);
}
void ChangeSpeedBall::Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    ball->SetSpeed();
}

TYPE_BONUS ChangeSpeedBall::GetType() const { return TYPE_BONUS::SPEED_UP; }
