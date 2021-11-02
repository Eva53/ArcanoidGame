#pragma once

#include "Project.hpp"
#include "Bonus.hpp"

class BallSticking : public Bonus
{
public:
    BallSticking(const Vector2f &pos);
    virtual ~BallSticking() = default;
    
    virtual TYPE_BONUS GetType() const override;
    virtual void Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field) override;
};
