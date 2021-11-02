#pragma once

#include "Project.hpp"
#include "Objects.hpp"

class Paddle : public Objects
{
private:
    float width;
    float height;
    RectangleShape paddle;
public:
    Paddle();
    virtual ~Paddle() = default;

    void UpdatePaddleWidth();
    void ChangePaddleWidth();
    void UpdatePosition(float x, float y) override;
    FloatRect GetGlobalBounds() const override;
    virtual void Draw(shared_ptr<RenderWindow> window) override;
};
