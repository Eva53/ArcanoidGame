#include "Project.hpp"
#include "Game.hpp"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Game game;
    game.Run();
    return 0;
}
