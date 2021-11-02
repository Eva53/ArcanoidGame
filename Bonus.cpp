#include "Bonus.hpp"

Bonus::Bonus(){
    Vector2f size_bonus(10, 10);
    bonus.setSize(size_bonus);
    bonus.setOutlineColor(Color::Green);
    bonus.setOutlineThickness(1.0);
}

void Bonus::Draw(shared_ptr<RenderWindow> window)
{
    bonus.setPosition(GetPosition());
    window->draw(bonus);
}

FloatRect Bonus::GetGlobalBounds() const { return bonus.getGlobalBounds(); }

void Bonus::UpdateBonusPosition() { SetUpdatePositionY(BONUS_FALL_SPEED); }

void Bonus::SetBonusColor(const Color &color) { bonus.setFillColor(color); }
