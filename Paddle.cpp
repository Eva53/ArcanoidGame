#include "Paddle.hpp"

Paddle::Paddle() : width(PADDLE_WIDTH), height(PADDLE_HEIGHT)
{
    paddle.setSize(Vector2f(width, height));
    paddle.setOutlineThickness(PADDLE_FRAME);
    paddle.setOutlineColor(Color::Red);
    paddle.setFillColor(Color::Green);
    SetPosition(PADDLE_X,PADDLE_Y);
}

void Paddle::UpdatePaddleWidth() {
    width = PADDLE_WIDTH;
    paddle.setSize(Vector2f(width, height));
}

void Paddle::ChangePaddleWidth()
{
    width = NEW_PADDLE_WIDTH;
    paddle.setSize(Vector2f(width, height));
}

void Paddle::Draw(shared_ptr<RenderWindow> window)
{
    paddle.setPosition(GetPosition());
    window->draw(paddle);
}

void Paddle::UpdatePosition(float x, float y)
{
    SetUpdatePositionX(x);
    SetUpdatePositionY(y);
    if (GetPositionX() < 0)
        SetPosition(0,PADDLE_Y);
    else if (width == PADDLE_WIDTH && GetPositionX() > WIDTH_WINDOW - PADDLE_WIDTH)
        SetPosition(WIDTH_WINDOW - PADDLE_WIDTH,PADDLE_Y);
    else if (width == NEW_PADDLE_WIDTH && GetPositionX() > WIDTH_WINDOW - NEW_PADDLE_WIDTH)
        SetPosition(WIDTH_WINDOW - NEW_PADDLE_WIDTH,PADDLE_Y);
}

FloatRect Paddle::GetGlobalBounds() const { return paddle.getGlobalBounds(); }
