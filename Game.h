#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    // Event helpers
    void handleKeyPressed(sf::Keyboard::Key key);
    void handleMousePressed(sf::Mouse::Button button, int x, int y);
    void handleMouseMoved(int x, int y);

private:
    sf::RenderWindow m_window;

    // Example state (stub for later assignments)
    bool m_paused = false;
    sf::Vector2i m_mousePos{0, 0};
};
