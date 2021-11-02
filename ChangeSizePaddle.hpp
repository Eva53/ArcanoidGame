#pragma once

#include "Project.hpp"
#include "Bonus.hpp"

class ChangeSizePaddle : public Bonus
{
public:
    ChangeSizePaddle(const Vector2f &pos);
    virtual ~ChangeSizePaddle() = default;
    
    virtual TYPE_BONUS GetType() const override; 
    virtual void Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field) override;
};
