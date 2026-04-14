#include "Game.h"
#include <iostream>

Game::Game()
    : m_window(sf::VideoMode({1000, 700}), "Powerclick - Assignment 1")
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
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::KeyPressed)
            handleKeyPressed(event.key.code);
        else if (event.type == sf::Event::MouseButtonPressed)
            handleMousePressed(event.mouseButton.button, sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        else if (event.type == sf::Event::MouseMoved)
            handleMouseMoved(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
    }
}

void Game::handleKeyPressed(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Key::Escape)
    {
        // ESC closes the window
        m_window.close();
    }
    else if (key == sf::Keyboard::Key::P)
    {
        // P toggles pause (useful later for debugging)
        m_paused = !m_paused;
        std::cout << (m_paused ? "Paused\n" : "Unpaused\n");
    }
}

void Game::handleMousePressed(sf::Mouse::Button button, sf::Vector2i position)
{
    if (button == sf::Mouse::Button::Left)
    {
        // Click position (this is the core interaction for a clicker game)
        std::cout << "Left click at: (" << position.x << ", " << position.y << ")\n";

        // Later: you’ll check if an enemy was clicked and remove it / subtract HP, etc.
        // Example idea:
        // if (enemyBounds.contains((float)x, (float)y)) { enemy.takeDamage(); }
    }
}

void Game::handleMouseMoved(sf::Vector2i position)
{
    m_mousePos = position;
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
