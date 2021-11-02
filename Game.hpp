#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"
#include "GameControl.hpp"
#include "Project.hpp"
#include "Bonus.hpp"

class Game
{
    Font font;
    Text text;
    
    int score;
    int health;
    bool isActiveFloor;
    
    shared_ptr <RenderWindow> window;
    shared_ptr<GameController> initActions;
    
    void Draw();
    void DrawScore();
    void DrawHealth();
    void DrawBackground();
    bool IsRunning() const;
    STATE_GAME EndGame() const;
public:
    Game();
    ~Game() = default;
    
    void Run();
};
