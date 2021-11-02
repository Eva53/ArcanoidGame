#include "GameControl.hpp"

GameController::GameController(){
    field = make_shared<Field>();
    curBrick = make_shared<Brick>();
    ball = make_shared<Ball>();
    paddle = make_shared<Paddle>();
    
    floor.setSize(Vector2f(FLOOR_SIZE_X, FLOOR_SIZE_Y));
    floor.setPosition(0, FLOOR_POSITION_Y);
    floor.setFillColor(Color::White);
}

void GameController::DrawBonuses(shared_ptr<RenderWindow> window, bool* isActiveFloor)
{
    for (auto it = bonusArr.begin(); it != bonusArr.end(); it++)
    {
        (*it)->Draw(window);
        
        (*it)->UpdateBonusPosition();
        if ((*it)->GetGlobalBounds().intersects(paddle->GetGlobalBounds()))
        {
            (*it)->Create(paddle, ball, field);
            if ((*it)->GetType() == TYPE_BONUS::SET_BOTTOM) {
                (*isActiveFloor) = true;
            }
            bonusArr.erase(it);
            if (bonusArr.empty())
                return;
            else
                it = bonusArr.begin();
        }
        else if ((*it)->GetPosition().y > HEIGHT_WINDOW - 4 * BALL_RADIUS - WIDTH_BRICK)
        {
            bonusArr.erase(it);
            if (bonusArr.empty())
                return;
            else
                it = bonusArr.begin();
        }
    }
}

void GameController::IsActive(shared_ptr< Ball> ball, shared_ptr< Paddle> paddle, int* score)
{
    ball->UpdatePosition();
    field->CollisionDetected(ball, score, paddle, &curBrick);
    this->PaddleCollide(ball, paddle);
    if (field->IsBonus())
    {
         this->CreateBonus(curBrick);
        field->IsNotBonus();
    }
    ball->UpdatePosition();
}

void GameController::CreateBonus(shared_ptr<Brick> brick)
{
    TYPE_BONUS type = TYPE_BONUS(rand() % BONUSES_PROBABILITY);
    switch (type)
    {
    case TYPE_BONUS::CHANGE_SIZE_PADDLE:
      bonusArr.push_back(make_shared<ChangeSizePaddle>(brick->GetPosition()));
        break;
    case TYPE_BONUS::MOVING_BRICK:
        bonusArr.push_back(make_shared<MovingBrick>(brick->GetPosition()));
        break;
        case TYPE_BONUS::CHANGE_DIRECTION:
        bonusArr.push_back(make_shared<ChangeDirection>(brick->GetPosition()));
        break;
    case TYPE_BONUS::STICKY_BALL:
        bonusArr.push_back(make_shared<BallSticking>(brick->GetPosition()));
        break;
    case TYPE_BONUS::SET_BOTTOM:
        bonusArr.push_back(make_shared<Floor>(brick->GetPosition()));
        break;
    case TYPE_BONUS::SPEED_UP:
        bonusArr.push_back(make_shared<ChangeSpeedBall>(brick->GetPosition()));
        break;
    default:
        break;
    }
}

bool GameController::DestroyedBricks() const { return field->CheckAll(); }

void GameController::GameProcess(int* scoreTotal, int* healthTotal, bool* isActiveFloor)
{
    if (Keyboard::isKeyPressed(Keyboard::Space))
        ball->ActivateBall();

    if (Keyboard::isKeyPressed(Keyboard::Right))
        paddle->UpdatePosition(4 * abs(SPEED), 0);
    else if (Keyboard::isKeyPressed(Keyboard::Left))
        paddle->UpdatePosition(-4 * abs(SPEED), 0);
    if (ball->MovingBall())
        this->IsActive(ball, paddle, scoreTotal);
    else
        ball->BallSetPosition(paddle->GetPosition().x + PADDLE_WIDTH / 2.0 - BALL_RADIUS, paddle->GetPosition().y - 3 * BALL_RADIUS + 2 * WIDTH);
    if (ball->GetFloor() && ball->GetPosition().x != (paddle->GetPosition().x + HEIGHT_BRICK - 2 * BALL_RADIUS) && ball->GetPosition().y > (HEIGHT_WINDOW - 4 * BALL_RADIUS - PADDLE_WIDTH + 20))
    {
        ball->ActivateBall();
        ball->ChangeSpeed(COLLISION_TYPE::PADDLE);
        ball->SetFloor(false);
        (*isActiveFloor) = false;
    }
    else if (ball->GetPosition().y > HEIGHT_WINDOW - 4 * BALL_RADIUS - PADDLE_WIDTH + 20)
    {
        ball->DeactivateBall();
        paddle->UpdatePaddleWidth();
        (*scoreTotal)--;
        (*healthTotal)--;
    }
}

void GameController::Draw(shared_ptr<RenderWindow> window)
{
    field->DrawBricks(window);
    paddle->Draw(window);
    ball->Draw(window);
}

void GameController::PaddleCollide(shared_ptr<Ball> ball, shared_ptr<Paddle> paddle)
{
    if (ball->GetGlobalBounds().intersects(paddle->GetGlobalBounds()))
    {
        ball->ChangeSpeed(COLLISION_TYPE::PADDLE);
        if (ball->GetSticking())
        {
            ball->UpdateSticking();
            ball->DeactivateBall();
        }
    }
}

void GameController::DrawFloor(shared_ptr<RenderWindow> window) {
    window->draw(floor);
}
