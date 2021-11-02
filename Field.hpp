#pragma once

#include "Project.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"

class Field {  
private:
    bool isBonus;
    vector<shared_ptr<Brick>> grid;
public:
    Field();
    ~Field() = default;
    
    void CollisionBricks(shared_ptr<Brick> brick);
    bool IsBonus() const;
    bool CheckAll() const;
    void IsNotBonus();
    void CreateMovingBrick();
    void MoveBrick(shared_ptr<Brick> brick);
    void DrawBricks(shared_ptr<RenderWindow> window);
    COLLISION_TYPE IsCollision(shared_ptr<Brick> brick, shared_ptr<Ball> ball) const;
    void CollisionDetected(shared_ptr<Ball> ball, int* totalScore, shared_ptr< Paddle> paddle, shared_ptr<Brick>* curBrick);
};
