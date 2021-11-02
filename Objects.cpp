#include "Objects.hpp"

Objects::Objects() {}

const Vector2f& Objects::GetPosition() const { return position; }

void Objects::SetPosition (float x, float y){
    position.x = x;
    position.y = y;
}

void Objects::SetUpdatePositionX (float x){ position.x += x; }

void Objects::SetUpdatePositionY (float y){ position.y += y; }

float Objects::GetPositionX() const { return position.x; }

float Objects::GetPositionY() const { return position.y; }
