#include "Ball.hpp"

Ball::Ball() :
    ballSpeed({-SPEED, -SPEED}),
    ballActive(false),
    ballFloor(false),
    ballSticking(0)
{
    ball.setRadius(BALL_RADIUS);
    ball.setFillColor(Color::White);
    SetPosition(BALL_X, BALL_Y);
}

void Ball::Draw(shared_ptr<RenderWindow> window) { window->draw(ball); }

void Ball::SetSpeed()
{
    if (ballSpeed.vx <= MAX_SPEED && ballSpeed.vy <= MAX_SPEED) {
        ballSpeed.vx += ((SPEED_CHANGE) * fabs(ballSpeed.vx) / ballSpeed.vx);
        ballSpeed.vy += ((SPEED_CHANGE) * fabs(ballSpeed.vy) / ballSpeed.vy);
    }
}

void Ball::BallSetPosition(float x, float y)
{
    SetPosition(x, y);
    ball.setPosition(GetPosition());
}

bool Ball::MovingBall() const { return ballActive; }

void Ball::ActivateBall() { ballActive = true; }

void Ball::DeactivateBall()
{
    ballSpeed.vx = SPEED;
    ballSpeed.vy = -SPEED;
    ballActive = false;
}

void Ball::UpdatePosition()
{
    SetUpdatePositionX(ballSpeed.vx);
    SetUpdatePositionY(ballSpeed.vy);
    
  if (GetPositionX() < 2 * BALL_RADIUS)
    {
        SetUpdatePositionX(-ballSpeed.vx);
        ballSpeed.vx = fabs(ballSpeed.vx);
    }
    else if (GetPositionX() > WIDTH_WINDOW - 4 * BALL_RADIUS)
    {
        SetUpdatePositionX(-ballSpeed.vx);
        ballSpeed.vx = -fabs(ballSpeed.vx);
    }
    else if (GetPositionY() < 2 * BALL_RADIUS)
    {
        SetUpdatePositionY(-ballSpeed.vy);
        ballSpeed.vy = fabs(ballSpeed.vy);
    }
    ball.setPosition(GetPositionX(), GetPositionY());
}

void Ball::ChangeSpeed(COLLISION_TYPE type)
{
    switch (type)
    {
    case COLLISION_TYPE::ANGLES:
        ballSpeed.vx *= -1;
        ballSpeed.vy *= -1;
        break;
    case COLLISION_TYPE::ANGLE:
        ballSpeed.vx *= -1;
        ballSpeed.vy *= -1;
        break;
    case COLLISION_TYPE::SIDE0:
        ballSpeed.vy = -fabs(ballSpeed.vy);
        break;
    case COLLISION_TYPE::SIDE1:
        ballSpeed.vy = fabs(ballSpeed.vy);
        break;
    case COLLISION_TYPE::SIDE2:
        ballSpeed.vx = -fabs(ballSpeed.vx);
        break;
    case COLLISION_TYPE::SIDE3:
        ballSpeed.vx = fabs(ballSpeed.vx);
        break;
    case COLLISION_TYPE::PADDLE:
        ballSpeed.vy *= -1;
        break;
    default:
        break;
    }
}

void Ball::UpdateSticking() { ballSticking = false; }

bool Ball::GetSticking() const { return ballSticking; }

void Ball::SetSticking() { ballSticking = true; }

bool Ball::GetFloor() const { return ballFloor; }

void Ball::SetFloor(bool param) { ballFloor = param; }

FloatRect Ball::GetGlobalBounds() const { return ball.getGlobalBounds(); }
