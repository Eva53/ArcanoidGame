#pragma once
#include "Project.hpp"
#include "Bonus.hpp"

class Floor : public Bonus
{
public:
    Floor(const Vector2f &pos);
    virtual ~Floor() = default;
    
    virtual TYPE_BONUS GetType() const override;
    virtual void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field)override;
};
