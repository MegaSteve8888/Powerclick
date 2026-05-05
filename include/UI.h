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
    int checkMainMenuClick(int mouseX, int mouseY);
    int checkGameOverClick(int mouseX, int mouseY);
    void updateFinalScore(int score);

private:
    sf::Font m_font;

    // HUD
    sf::Text m_scoreText;
    sf::Text m_livesText;

    // Screens
    sf::Text m_titleText;
    sf::Text m_startText;
    sf::Text m_difficultyText;
    sf::Text m_gameOverText;
    sf::Text m_finalScoreText;
    sf::Text m_restartText;

    // button textures and sprites
    sf::Texture m_titleTex;
    sf::Sprite m_titleSprite;
    sf::Texture m_playTex;
    sf::Sprite m_playSprite;
    sf::Texture m_highscoreTex;
    sf::Sprite m_highscoreSprite;
    sf::Texture m_quitTex;
    sf::Sprite m_quitSprite;

    sf::Texture m_gameoverTex;
    sf::Sprite m_gameoverSprite;
    sf::Texture m_restartBtnTex;
    sf::Sprite m_restartBtnSprite;
    sf::Texture m_mainmenuTex;
    sf::Sprite m_mainmenuSprite;
    sf::Texture m_quitGoTex;
    sf::Sprite m_quitGoSprite;

    //high score
    sf::Texture m_highscoreTitleTex;
    sf::Sprite m_highscoreTitleSprite;
    sf::Texture m_backTex;
    sf::Sprite m_backSprite;
};
