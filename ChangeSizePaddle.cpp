#include "ChangeSizePaddle.hpp"

ChangeSizePaddle::ChangeSizePaddle(const Vector2f &pos)
{ 
    SetPosition(pos.x + START_BONUS_POSX, pos.y + START_BONUS_POSY);
    SetBonusColor(Color::White);
}

void ChangeSizePaddle::Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field)
{
    paddle->ChangePaddleWidth();
}

TYPE_BONUS ChangeSizePaddle::GetType() const { return TYPE_BONUS::CHANGE_SIZE_PADDLE; }
