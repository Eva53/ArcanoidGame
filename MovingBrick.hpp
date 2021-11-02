#pragma once
#include "Project.hpp"
#include "Bonus.hpp"

class MovingBrick : public Bonus
{
public:
    MovingBrick(const Vector2f &pos);
    virtual ~MovingBrick() = default;
    
    virtual TYPE_BONUS GetType() const override;
    virtual void Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field) override;
};
