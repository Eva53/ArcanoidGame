#pragma once

#include "Project.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Field.hpp"
#include "Bonus.hpp"
#include "MovingBrick.hpp"
#include "ChangeDirection.hpp"
#include "ChangeSpeedBall.hpp"
#include "ChangeSizePaddle.hpp"
#include "Floor.hpp"
#include "BallSticking.hpp"

class GameController
{
private:
    shared_ptr<Ball> ball;
    shared_ptr<Field> field;
    shared_ptr<Paddle> paddle;
    shared_ptr<Brick> curBrick;
    vector<shared_ptr<Bonus>> bonusArr;
    RectangleShape floor;
public:
    GameController();
    ~GameController() = default;

    bool DestroyedBricks() const;
    void GameProcess(int* scoreTotal, int* healthTotal, bool* isActiveFloor);
    void CreateBonus(shared_ptr<Brick> brick);
    void Draw(shared_ptr<RenderWindow> window);
    void DrawBonuses(shared_ptr<RenderWindow> window, bool* isActiveFloor);
    void DrawFloor(shared_ptr<RenderWindow> window);
    void PaddleCollide(shared_ptr<Ball> ball, shared_ptr<Paddle> paddle);
    void IsActive(shared_ptr<Ball> ball, shared_ptr< Paddle> paddle, int* score);
};
