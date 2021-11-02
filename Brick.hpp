#pragma once

#include "Project.hpp"
#include "Objects.hpp"
#include "Ball.hpp"

class Brick : public Objects
{
private:
    int brickLevel;
    int moveOfBrick;
    bool destroyed;
    bool brickSpeed;
    bool movingBrick;
    bool brickBonus;
    
    RectangleShape brick;
    RectangleShape line[4];
    RectangleShape corner[4];
    
public:
    Brick(int brickLevel, int x, int y, int _spaceX, int _spaceY);
    Brick() : brickLevel(0), destroyed(false), brickSpeed(false), brickBonus(false), moveOfBrick(fabs(SPEED)), movingBrick(false) {};
    virtual ~Brick() = default;

    void Destroy();
    int GetLevel()const;
    bool IsMovingBrick()const;
    void SetMovingBrick();
    bool Destroyed() const;
    void SetDirection();
    bool IncreaseSpeed()const;
    TYPE_BRICK GetType()const;
    void UpdatePosition();
    void SetType(TYPE_BRICK type);
    void SetLevel(int brickLevel);
    void UpdatePosition(float x, float y) override {};
    FloatRect GetGlobalBounds() const override;
    COLLISION_TYPE TypeCollision(shared_ptr<Ball> ball) const;
    virtual void Draw(shared_ptr<RenderWindow> window) override;
};
