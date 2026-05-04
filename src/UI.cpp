#include "UI.h"
#include <iostream>

UI::UI(): m_font("assets/fonts/arial.ttf"), m_scoreText(m_font), m_livesText(m_font), m_titleText(m_font), m_startText(m_font), m_gameOverText(m_font), m_finalScoreText(m_font), m_restartText(m_font)
{

    // HUD text
   
    m_scoreText.setCharacterSize(20);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(sf::Vector2f(10.f, 10.f));


    m_livesText.setCharacterSize(20);
    m_livesText.setFillColor(sf::Color::White);
    m_livesText.setPosition(sf::Vector2f(10.f, 40.f));

    // Title (Main Menu)

    m_titleText.setString("POWERCLICK");
    m_titleText.setCharacterSize(50);
    m_titleText.setFillColor(sf::Color::Yellow);
    m_titleText.setPosition(sf::Vector2f(300.f, 150.f));

    m_startText.setString("Press ENTER to Start");
    m_startText.setCharacterSize(25);
    m_startText.setFillColor(sf::Color::White);
    m_startText.setPosition(sf::Vector2f(320.f, 300.f));

    // Game Over
  
    m_gameOverText.setString("GAME OVER");
    m_gameOverText.setCharacterSize(50);
    m_gameOverText.setFillColor(sf::Color::Red);
    m_gameOverText.setPosition(sf::Vector2f(320.f, 250.f));
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
