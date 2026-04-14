#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class UI
{
public:
    UI();

    void updateScore(int score);
    void updateLives(int lives);

    void drawHUD(sf::RenderWindow& window);
    void drawMainMenu(sf::RenderWindow& window);
    void drawGameOver(sf::RenderWindow& window);

private:
    sf::Font m_font;

    // HUD
    sf::Text m_scoreText;
    sf::Text m_livesText;

    // Screens
    sf::Text m_titleText;
    sf::Text m_startText;
    sf::Text m_gameOverText;
};
