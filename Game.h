#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "UI.h"

// Game states
enum class GameState
{
    Menu,
    Playing,
    GameOver
};

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    void handleKeyPressed(sf::Keyboard::Key key);
    void handleMousePressed(sf::Mouse::Button button, int x, int y);
    void handleMouseMoved(int x, int y);

    void spawnEnemy();

private:
    sf::RenderWindow m_window;

    GameState m_state = GameState::Menu;

    std::vector<Enemy> m_enemies;
    UI m_ui;

    int m_score = 0;
    int m_lives = 3;

    float m_spawnTimer = 0.f;

    bool m_paused = false;
    sf::Vector2i m_mousePos{0, 0};
};
