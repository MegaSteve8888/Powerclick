#include "Game.h"
#include <iostream>

Game::Game()
    : m_window(sf::VideoMode(1000, 700), "Powerclick - Assignment 1")
{
    // Optional: cap FPS so the loop doesn't run too fast
    m_window.setFramerateLimit(60);
}

void Game::run()
{
    sf::Clock clock;

    while (m_window.isOpen())
    {
        // dt = seconds since last frame
        float dt = clock.restart().asSeconds();

        processEvents();

        if (!m_paused)
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

void Game::handleKeyPressed(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Escape)
    {
        // ESC closes the window
        m_window.close();
    }
    else if (key == sf::Keyboard::P)
    {
        // P toggles pause (useful later for debugging)
        m_paused = !m_paused;
        std::cout << (m_paused ? "Paused\n" : "Unpaused\n");
    }
}

void Game::handleMousePressed(sf::Mouse::Button button, int x, int y)
{
    if (button == sf::Mouse::Left)
    {
        // Click position (this is the core interaction for a clicker game)
        std::cout << "Left click at: (" << x << ", " << y << ")\n";

        // Later: you’ll check if an enemy was clicked and remove it / subtract HP, etc.
        // Example idea:
        // if (enemyBounds.contains((float)x, (float)y)) { enemy.takeDamage(); }
    }
}

void Game::handleMouseMoved(int x, int y)
{
    m_mousePos = {x, y};
    // Later: hover effects / cursor UI / aim indicator, etc.
}

void Game::update(float dt)
{
    // Stub for later assignments:
    // - spawn enemies over time
    // - move enemies toward the house
    // - check win/lose conditions
    (void)dt; // prevents unused warning until you implement logic
}

void Game::render()
{
    m_window.clear();

    // Stub: draw background / enemies / UI later

    m_window.display();
}
