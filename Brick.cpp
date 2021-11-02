#include "Brick.hpp"

Brick::Brick(int brickLevel, int x, int y, int _spaceX, int _spaceY) :
    destroyed(false),
    brickSpeed(false),
    brickBonus(false),
    moveOfBrick(fabs(SPEED)),
    movingBrick(false)
{
    float a = x * (WIDTH_BRICK + 2 * WIDTH) + WIDTH_ / 2.0;
    float b = y * (HEIGHT_BRICK + 2 * WIDTH) + WIDTH_ / 2.0 + 40;
    SetPosition(a, b);
    this->brickLevel = brickLevel;
    brick.setSize(Vector2f(WIDTH_BRICK, HEIGHT_BRICK));

    corner[0].setSize(Vector2f(WIDTH, WIDTH));
    corner[1].setSize(Vector2f(WIDTH, WIDTH));
    corner[2].setSize(Vector2f(WIDTH, WIDTH));
    corner[3].setSize(Vector2f(WIDTH, WIDTH));
    
    corner[0].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, (y + 1) * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
    corner[1].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, (y + 1) * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
    corner[2].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);
    corner[3].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);

    line[0].setSize(Vector2f(WIDTH_BRICK, WIDTH));
    line[1].setSize(Vector2f(WIDTH_BRICK, WIDTH));
    line[2].setSize(Vector2f(WIDTH, HEIGHT_BRICK));
    line[3].setSize(Vector2f(WIDTH, HEIGHT_BRICK));

    line[0].setPosition(x * (WIDTH_BRICK - WIDTH) + (x + 2) * WIDTH + 2 * _spaceX + WIDTH_ / 2.0, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);
    line[1].setPosition(x * (WIDTH_BRICK - WIDTH) + (x + 2) * WIDTH + 2 * _spaceX + WIDTH_  / 2.0, (y + 1) * ((HEIGHT_BRICK + WIDTH)) + _spaceY + 40);
    line[2].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, y * (HEIGHT_BRICK + WIDTH) + WIDTH + _spaceY + WIDTH_  / 2.0 + 40);
    line[3].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + WIDTH + _spaceY + WIDTH_  / 2.0 + 40);

    brick.setPosition(GetPosition());
}

TYPE_BRICK Brick::GetType() const
{
    if (brickBonus)
        return TYPE_BRICK::BONUS;
    return TYPE_BRICK::SPEED_UP_BALL;
}

COLLISION_TYPE Brick::TypeCollision(shared_ptr<Ball> ball) const
{
    FloatRect ball_ = ball->GetGlobalBounds();

    FloatRect c0 = corner[0].getGlobalBounds();
    FloatRect c1 = corner[1].getGlobalBounds();
    FloatRect c2 = corner[2].getGlobalBounds();
    FloatRect c3 = corner[3].getGlobalBounds();

    bool angle0 = c0.intersects(ball_);
    bool angle1 = c1.intersects(ball_);
    bool angle2 = c2.intersects(ball_);
    bool angle3 = c3.intersects(ball_);

    FloatRect l0 = line[0].getGlobalBounds();
    FloatRect l1 = line[1].getGlobalBounds();
    FloatRect l2 = line[2].getGlobalBounds();
    FloatRect l3 = line[3].getGlobalBounds();

    bool side0 = l0.intersects(ball_);
    bool side1 = l1.intersects(ball_);
    bool side2 = l2.intersects(ball_);
    bool side3 = l3.intersects(ball_);
    
    if (angle0 || angle1 || angle2 || angle3 || side0 || side1 || side2 || side3)
    {
        if (angle0 && angle1 && angle2)
            return COLLISION_TYPE::ANGLES;
        if (angle0 || angle1 || angle2 || angle3)
            return COLLISION_TYPE::ANGLE;
        else if(side0)
            return COLLISION_TYPE::SIDE0;
        else if (side1)
            return COLLISION_TYPE::SIDE1;
        else if (side2)
            return COLLISION_TYPE::SIDE2;
        else if (side3)
            return COLLISION_TYPE::SIDE3;
    }
    else
    {
        return COLLISION_TYPE::NO_COLLISION;
    }
}

void Brick::UpdatePosition()
{
    SetUpdatePositionX(moveOfBrick);
    for (int i = 0; i < 4; i++)
    {
        line[i].setPosition(line[i].getPosition().x + moveOfBrick, line[i].getPosition().y);
        corner[i].setPosition(corner[i].getPosition().x + moveOfBrick, corner[i].getPosition().y);
    }
    if (GetPositionX() < 2 * BALL_RADIUS)
    {
        for (int i = 0; i < 4; i++)
        {
            line[i].setPosition(line[i].getPosition().x - moveOfBrick, line[i].getPosition().y);
            corner[i].setPosition(corner[i].getPosition().x - moveOfBrick, corner[i].getPosition().y);
        }
        SetUpdatePositionX(-moveOfBrick);
        moveOfBrick = fabs(moveOfBrick);
    }
    else if (GetPositionX() > WIDTH_WINDOW - 20 * BALL_RADIUS)
    {
        for (int i = 0; i < 4; i++)
        {
            line[i].setPosition(line[i].getPosition().x - moveOfBrick, line[i].getPosition().y);
            corner[i].setPosition(corner[i].getPosition().x - moveOfBrick, corner[i].getPosition().y);
        }
        SetUpdatePositionX(-moveOfBrick);
        moveOfBrick = -fabs(moveOfBrick);
    }
    brick.setPosition(GetPositionX(), GetPositionY());
}

void Brick::SetDirection() { moveOfBrick *= -1; }

bool Brick::Destroyed() const { return destroyed; }

int Brick::GetLevel() const { return brickLevel; }

void Brick::Destroy()
{
    if (brickLevel == 0)
    {
        destroyed = true;
        for (int i = 0; i < 4; i++)
        {
            line[i].setPosition(-1000, 0);
            corner[i].setPosition(-1000, 0);
        }
        brick.setPosition(-1000, 0);
    }
    else if (brickLevel != 3)
    {
        brickLevel--;
    }
}

void Brick::Draw(shared_ptr<RenderWindow> window)
{
    switch (brickLevel)
    {
    case COLOR_TYPE_BRICK::WHITE:
            brick.setFillColor(Color::White);
        break;
    case COLOR_TYPE_BRICK::CYAN:
            brick.setFillColor(Color::Cyan);
        break;
    case COLOR_TYPE_BRICK::RED:
            brick.setFillColor(Color::Red);
        break;
    case COLOR_TYPE_BRICK::GREY:
            brick.setFillColor(Color(105, 105, 105));
        break;
    };
    for (int i = 0; i < 4; i++)
    {
        line[i].setFillColor(brick.getFillColor());
        corner[i].setFillColor(brick.getFillColor());
        window->draw(corner[i]);
        window->draw(line[i]);
    }
    window->draw(brick);
}

void Brick::SetLevel(int brickLevel) { this->brickLevel = brickLevel; }

FloatRect Brick::GetGlobalBounds() const { return brick.getGlobalBounds(); }

bool Brick::IncreaseSpeed() const { return brickSpeed; }

void Brick::SetType(TYPE_BRICK type)
{
    if (type == TYPE_BRICK::SPEED_UP_BALL)
        brickSpeed = true;
    else if (type == TYPE_BRICK::BONUS)
        brickBonus = true;
}

bool Brick::IsMovingBrick() const { return movingBrick; }

void Brick::SetMovingBrick() { movingBrick = true; }
