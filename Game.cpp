#include "Game.hpp"
#include "ResourcePath.hpp"

Game::Game() :
    score(0),
    health(3),
    isActiveFloor(false),
    initActions(make_shared<GameController>())
{
    this->window = make_shared<RenderWindow>(VideoMode((unsigned int)WIDTH_WINDOW, (unsigned int)HEIGHT_WINDOW), "Arcanoid");
    this->window->setFramerateLimit(FRAMERATE_LIMIT);
        if (!font.loadFromFile(resourcePath() + "Lato.ttf"))
            return EXIT_FAILURE;
}

STATE_GAME Game::EndGame() const
{
    if (initActions->DestroyedBricks() || health == 0) {
        return STATE_GAME::GAME_OVER;
    }
    return STATE_GAME::GAME_PLAY;
}

void Game::Run()
{
    while (IsRunning() && this->EndGame() != STATE_GAME::GAME_OVER)
    {
        Event event;
        if (window->pollEvent(event))
            if (event.type == Event::Closed)
                window->close();
        initActions->GameProcess(&score, &health, &isActiveFloor);
        if (this->EndGame() == STATE_GAME::GAME_OVER)
        {
            this->DrawBackground();
            std::string textScore = "GAME OVER. Your score: " + to_string(score);
            text.setString(textScore);
            text.setFont(font);
            text.setCharacterSize(SIZE_FONT);
            text.setPosition(TEXT_GAME_OVER_X, TEXT_GAME_OVER_Y);
            window->draw(text);
            window->display();
            while (!Keyboard::isKeyPressed(Keyboard::Return));
            window->close();
        }
        this->Draw();
    }
}

bool Game::IsRunning() const
{
    if (window->isOpen())
        return true;
    return false;
}

void Game::DrawBackground()
{
    window->clear();
    RectangleShape background;
    background.setSize(Vector2f(WIDTH_WINDOW, HEIGHT_WINDOW));
    background.setPosition(0.0, 0.0);
    background.setFillColor(Color::Black);
    window->draw(background);
}

void Game::DrawScore()
{
    std::string textScore = "Score: " + to_string(score);
    text.setString(textScore);
    text.setFont(font);
    text.setCharacterSize(SIZE_FONT);
    text.setPosition(TEXT_X, TEXT_Y);
    window->draw(text);
}

void Game::DrawHealth()
{
    std::string textHealth = "Health: " + to_string(health) + "/3";
    text.setString(textHealth);
    text.setFont(font);
    text.setCharacterSize(SIZE_FONT);
    text.setPosition(TEXT_HEALTH_X, TEXT_Y);
    window->draw(text);
}

void Game::Draw()
{
    window->clear();
    this->DrawBackground();
    this->DrawScore();
    this->DrawHealth();
    initActions->Draw(window);
    initActions->DrawBonuses(window, &isActiveFloor);
    if (isActiveFloor == true) {
        initActions->DrawFloor(window);
    }
    window->display();
}
