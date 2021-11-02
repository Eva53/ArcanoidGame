#pragma once

#include "Project.hpp"

class Objects
{
private:
  Vector2f position;
public:
  Objects();
  virtual ~Objects() = default;

  void SetPosition (float x, float y);
  void SetUpdatePositionX (float x);
  void SetUpdatePositionY (float y);
    
  float GetPositionX() const;
  float GetPositionY() const;
  const Vector2f& GetPosition() const;
    
  virtual FloatRect GetGlobalBounds() const = 0;
  virtual void UpdatePosition(float x, float y) = 0;
  virtual void Draw(shared_ptr<RenderWindow> window) = 0;
};
