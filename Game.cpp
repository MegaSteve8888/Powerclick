#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game()
    : m_window(sf::VideoMode(1000, 700), "Powerclick")
{
    m_window.setFramerateLimit(60);
}

void Game::run()
{
    sf::Clock clock;

    while (m_window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::KeyPressed:
            handleKeyPressed(event.key.code);
            break;

        case sf::Event::MouseButtonPressed:
            handleMousePressed(event.mouseButton.button,
                               event.mouseButton.x,
                               event.mouseButton.y);
            break;

        case sf::Event::MouseMoved:
            handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
            break;

        default:
            break;
        }
    }
}

void Game::spawnEnemy()
{
    int side = rand() % 4;
    float startX, startY;

    if (side == 0)
    {
        startX = -20;
        startY = rand() % 700;
    }
    else if (side == 1)
    {
        startX = 1020;
        startY = rand() % 700;
    }
    else if (side == 2)
    {
        startX = rand() % 1000;
        startY = -20;
    }
    else
    {
        startX = rand() % 1000;
        startY = 720;
    }

    m_enemies.emplace_back(startX, startY, m_enemySpeed);
}

void Game::update(float dt)
{
    if (m_state != GameState::Playing)
        return;

    // 🎯 Difficulty scaling
    m_difficultyTimer += dt;

    if (m_difficultyTimer > 10.f)
    {
        m_difficultyTimer = 0.f;

        m_enemySpeed += 20.f;

        if (m_spawnInterval > 0.5f)
            m_spawnInterval -= 0.2f;

        std::cout << "Difficulty increased!\n";
    }

    // Spawn enemies
    if (m_spawnClock.getElapsedTime().asSeconds() > m_spawnInterval)
    {
        spawnEnemy();
        m_spawnClock.restart();
    }

    sf::Vector2f housePosition(900.f, 350.f);

    for (auto& e : m_enemies)
        e.update(dt, housePosition);

    // Enemy reaches target
    for (auto it = m_enemies.begin(); it != m_enemies.end(); )
    {
        if (it->hasReachedTarget(housePosition))
        {
            it = m_enemies.erase(it);
            m_lives--;

            if (m_lives <= 0)
                m_state = GameState::GameOver;
        }
        else
        {
            ++it;
        }
    }

    m_ui.updateScore(m_score);
    m_ui.updateLives(m_lives);
}

void Game::handleMousePressed(sf::Mouse::Button button, int x, int y)
{
    if (button == sf::Mouse::Left && m_state == GameState::Playing)
    {
        for (auto it = m_enemies.begin(); it != m_enemies.end(); )
        {
            if (it->isClicked(x, y))
            {
                it = m_enemies.erase(it);

                // ⭐ Score scales with difficulty
                m_score += static_cast<int>(10 + m_enemySpeed / 20);
            }
            else
            {
                ++it;
            }
        }
    }
}

void Game::handleKeyPressed(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Escape)
        m_window.close();

    if (key == sf::Keyboard::Enter)
    {
        if (m_state == GameState::Menu)
        {
            m_state = GameState::Playing;
        }
        else if (m_state == GameState::GameOver)
        {
            m_state = GameState::Menu;
            m_score = 0;
            m_lives = 3;
            m_enemies.clear();

            // reset difficulty
            m_enemySpeed = 100.f;
            m_spawnInterval = 1.5f;
            m_difficultyTimer = 0.f;
        }
    }
}

void Game::handleMouseMoved(int x, int y)
{
    m_mousePos = {x, y};
}

void Game::render()
{
    m_window.clear();

    if (m_state == GameState::Menu)
    {
        m_ui.drawMainMenu(m_window);
    }
    else if (m_state == GameState::Playing)
    {
        for (auto& e : m_enemies)
            e.render(m_window);

        m_ui.drawHUD(m_window);
    }
    else if (m_state == GameState::GameOver)
    {
        m_ui.drawGameOver(m_window);
    }

    m_window.display();
}
