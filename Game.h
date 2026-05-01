#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "UI.h"

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

    // ⬇️ Difficulty system
    float m_difficultyTimer = 0.f;
    float m_spawnInterval = 1.5f;
    float m_enemySpeed = 100.f;

    sf::Clock m_spawnClock;

    bool m_paused = false;
    sf::Vector2i m_mousePos{0, 0};
};
