#include "Field.hpp"

Field::Field() : isBonus(false)
{
    float _spaceX = 0;
    for (int i = 1; i <= XNUMBRICKS; i++)
    {
        float _spaceY = 0;
        for (int j = 1; j <= YNUMBRICKS; j++)
        {
            if (j < 3) {
            grid.push_back(make_shared<Brick>(0, i, j, _spaceX, _spaceY));
            }
            else if (j == 3) {
            grid.push_back(make_shared<Brick>(2, i, j, _spaceX, _spaceY));
            }
            else if (j == 4 && (i == 1 || i == XNUMBRICKS)) {
            grid.push_back(make_shared<Brick>(2, i, j, _spaceX, _spaceY));
            }
            else if (j == 4 && (i > 3 && i < XNUMBRICKS - 2)) {
            grid.push_back(make_shared<Brick>(0, i, j, _spaceX, _spaceY));
            }
            else if (j == 4 && ((i > 1 && i <= 3) || (i >= XNUMBRICKS - 2 && i < XNUMBRICKS))) {
            grid.push_back(make_shared<Brick>(3, i, j, _spaceX, _spaceY));
            }
            else if (j == 5 && (i == 1 || i == XNUMBRICKS)) {
            grid.push_back(make_shared<Brick>(0, i, j, _spaceX, _spaceY));
            }
            else if (j == 5 && (i == 2 || i == XNUMBRICKS - 1)) {
            grid.push_back(make_shared<Brick>(3, i, j, _spaceX, _spaceY));
            }
            else if (j == 5 && (i > 2 || i < XNUMBRICKS - 1)) {
            grid.push_back(make_shared<Brick>(1, i, j, _spaceX, _spaceY));
            }
            else if (j == 6 && (i == 1 || i == XNUMBRICKS)) {
            grid.push_back(make_shared<Brick>(0, i, j, _spaceX, _spaceY));
            }
            else if (j == 6 && (i >= 2 || i <= XNUMBRICKS - 1)) {
            grid.push_back(make_shared<Brick>(1, i, j, _spaceX, _spaceY));
            }
            else if (j == 7 && (i == 1 || i == XNUMBRICKS)) {
            grid.push_back(make_shared<Brick>(2, i, j, _spaceX, _spaceY));
            }
            else if (j == 7 && (i == 2 || i == XNUMBRICKS - 1)) {
            grid.push_back(make_shared<Brick>(1, i, j, _spaceX, _spaceY));
            }
            else if (j == 7 && ((i > 2 && i <= 4) || (i >= 7 && i <= 8))) {
            grid.push_back(make_shared<Brick>(2, i, j, _spaceX, _spaceY));
            }
            else if (j == 7 && (i == 5 || i == 6)) {
            grid.push_back(make_shared<Brick>(1, i, j, _spaceX, _spaceY));
            }
            else if (j == 8 && (i == 1 || i == XNUMBRICKS)) {
            grid.push_back(make_shared<Brick>(2, i, j, _spaceX, _spaceY));
            }
            else if (j == 8 && (i >= 2 || i <= XNUMBRICKS - 1)) {
            grid.push_back(make_shared<Brick>(1, i, j, _spaceX, _spaceY));
            }
            _spaceY += WIDTH;
            int index = i * j - 1;
            if (rand() % MOVING_CHANCE > MOVING_PROBABILITY)
            {
                grid[index]->SetType(TYPE_BRICK::SPEED_UP_BALL);
            }
            else if (rand() % BONUS_CHANCE < BONUS_PROBABILITY)
            {
                grid[index]->SetType(TYPE_BRICK::BONUS);
            }

        }
        _spaceX += WIDTH;
    }
}
void Field::IsNotBonus() { isBonus = false; }

bool Field::IsBonus() const { return isBonus; }

void Field::DrawBricks(shared_ptr<RenderWindow> window)
{
    for (auto& it : grid)
    {
        it->Draw(window);
        if (it->IsMovingBrick() && !it->Destroyed())
        {
            MoveBrick(it);
        }
    }
}

void Field::MoveBrick(shared_ptr<Brick> brick)
{
    brick->UpdatePosition();
    this->CollisionBricks(brick);
}

COLLISION_TYPE Field::IsCollision(shared_ptr<Brick> brick, shared_ptr<Ball> ball) const
{
    return brick->TypeCollision(ball);
}

void Field::CreateMovingBrick()
{
    int x = rand() % XNUMBRICKS + 1;
    grid.push_back(make_shared<Brick>(rand() % 3, x, XNUMBRICKS - 1, x * WIDTH, (XNUMBRICKS - 2) * WIDTH));
    auto it = grid.end() - 1;
    (*it)->SetMovingBrick();
}

bool Field::CheckAll() const
{
    for (auto& it : grid)
    {
        if (it->GetLevel() != 3 && !it->Destroyed())
        {
            return false;
        }
    }
    return true;
}

void Field::CollisionDetected(shared_ptr<Ball> ball, int* totalScore, shared_ptr< Paddle> paddle, shared_ptr<Brick>* curBrick)
{
    int count = 0;
    for (auto it = grid.begin(); it != grid.end(); it++, count++)
    {
        COLLISION_TYPE type = IsCollision(*it, ball);
        if (type != COLLISION_TYPE::NO_COLLISION)
        {
            if (type == COLLISION_TYPE::ANGLES)
            {
                (*(it + YNUMBRICKS))->Destroy();
                (*(it + 1))->Destroy();
            }
            else
            {
                (*it)->Destroy();
            }
            if ((*it)->IncreaseSpeed())
            {
                ball->SetSpeed();
            }
            ball->ChangeSpeed(type);
            (*totalScore)++;
            if ((*it)->Destroyed() && (*it)->GetType() == TYPE_BRICK::BONUS)
            {
                (*curBrick) = (*it);
                isBonus = true;
            }
            if ((*it)->IsMovingBrick())
                ball->UpdatePosition();
            return;
        }
    }
}

void Field::CollisionBricks(shared_ptr<Brick> brick)
{
    for (auto& it : grid)
    {
        if (it != brick) {
            if (brick->GetGlobalBounds().intersects(it->GetGlobalBounds()))
            {

                brick->SetDirection();
                while (brick->GetGlobalBounds().intersects(it->GetGlobalBounds()))
                {
                    brick->UpdatePosition();
                }
            }
        }
    }
}
