#pragma once

#include "Project.hpp"
#include "Objects.hpp"
#include "Paddle.hpp"
#include "Field.hpp"
#include "Ball.hpp"

class Bonus : public Objects
{
private:
    RectangleShape bonus;
public:
    Bonus();
    virtual ~Bonus() = default;

    virtual TYPE_BONUS GetType() const = 0;
    void UpdateBonusPosition();
    void SetBonusColor(const Color &color);
    FloatRect GetGlobalBounds() const override;
    void UpdatePosition(float x, float y) override {};
    virtual void Draw(shared_ptr<RenderWindow> window) override;
    virtual void Create(shared_ptr< Paddle> paddle, shared_ptr<Ball> ball, shared_ptr<Field> field) = 0;
};
