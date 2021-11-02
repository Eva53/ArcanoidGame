#pragma once

#include "Project.hpp"
#include "Objects.hpp"

class Ball: public Objects
{
private:
    CircleShape ball;
    bool ballActive;
    bool ballSticking;
    bool ballFloor;
    speed_t ballSpeed;
public:
    Ball();
    ~Ball() = default;

    void SetSpeed();
    bool MovingBall() const;
    bool GetSticking() const;
    void SetSticking();
    void ActivateBall();
    void DeactivateBall();
    void UpdatePosition();
    void UpdateSticking();
    bool GetFloor() const;
    void BallSetPosition(float x, float y);
    void SetFloor(bool param);
    void ChangeSpeed(COLLISION_TYPE type);
    
    virtual FloatRect GetGlobalBounds() const override;
    virtual void UpdatePosition(float x, float y) override {};
    virtual void Draw(shared_ptr<RenderWindow> window)override;
};
