#include "UI.h"
#include <iostream>

UI::UI()
{
    // Load font (make sure file exists in project folder)
    if (!m_font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error loading font\n";
    }

    // HUD text
    m_scoreText.setFont(m_font);
    m_scoreText.setCharacterSize(20);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(10.f, 10.f);

    m_livesText.setFont(m_font);
    m_livesText.setCharacterSize(20);
    m_livesText.setFillColor(sf::Color::White);
    m_livesText.setPosition(10.f, 40.f);

    // Title (Main Menu)
    m_titleText.setFont(m_font);
    m_titleText.setString("POWERCLICK");
    m_titleText.setCharacterSize(50);
    m_titleText.setFillColor(sf::Color::Yellow);
    m_titleText.setPosition(300.f, 150.f);

    m_startText.setFont(m_font);
    m_startText.setString("Press ENTER to Start");
    m_startText.setCharacterSize(25);
    m_startText.setFillColor(sf::Color::White);
    m_startText.setPosition(320.f, 300.f);

    // Game Over
    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("GAME OVER");
    m_gameOverText.setCharacterSize(50);
    m_gameOverText.setFillColor(sf::Color::Red);
    m_gameOverText.setPosition(320.f, 250.f);
}

void UI::updateScore(int score)
{
    m_scoreText.setString("Score: " + std::to_string(score));
}

void UI::updateLives(int lives)
{
    m_livesText.setString("Lives: " + std::to_string(lives));
}

void UI::drawHUD(sf::RenderWindow& window)
{
    window.draw(m_scoreText);
    window.draw(m_livesText);
}

void UI::drawMainMenu(sf::RenderWindow& window)
{
    window.draw(m_titleText);
    window.draw(m_startText);
}

void UI::drawGameOver(sf::RenderWindow& window)
{
    window.draw(m_gameOverText);
}
