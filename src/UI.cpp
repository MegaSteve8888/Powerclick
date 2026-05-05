#include "UI.h"
#include "Constant.hpp"
#include <iostream>

UI::UI(): m_font("assets/fonts/arial.ttf"), m_scoreText(m_font), m_livesText(m_font),
 m_titleText(m_font), m_startText(m_font), m_difficultyText(m_font),
  m_gameOverText(m_font), m_finalScoreText(m_font), m_restartText(m_font),
   m_titleTex("assets/sprites/btn_title.png"), m_titleSprite(m_titleTex),
    m_playTex("assets/sprites/btn_play.png"), m_playSprite(m_playTex), m_highscoreTex("assets/sprites/btn_highscore.png"),
     m_highscoreSprite(m_highscoreTex), m_quitTex("assets/sprites/btn_quit.png"), m_quitSprite(m_quitTex),
      m_gameoverTex("assets/sprites/btn_gameover.png"), m_gameoverSprite(m_gameoverTex), m_restartBtnTex("assets/sprites/btn_restart.png"),
       m_restartBtnSprite(m_restartBtnTex), m_mainmenuTex("assets/sprites/btn_mainmenu.png"), m_mainmenuSprite(m_mainmenuTex),
        m_quitGoTex("assets/sprites/btn_quit_go.png"), m_quitGoSprite(m_quitGoTex), m_highscoreTitleTex("assets/sprites/btn_highscore_title.png"),
         m_highscoreTitleSprite(m_highscoreTitleTex), m_backTex("assets/sprites/btn_back.png"), m_backSprite(m_backTex),
          m_diffTitleTex("assets/sprites/btn_difficulty_title.png"), m_diffTitleSprite(m_diffTitleTex), m_normalTex("assets/sprites/btn_normal.png"),
           m_normalSprite(m_normalTex), m_hardTex("assets/sprites/btn_hard.png"), m_hardSprite(m_hardTex)
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

    m_startText.setString("Select Difficulty");
    m_startText.setCharacterSize(25);
    m_startText.setFillColor(sf::Color::White);
    m_startText.setPosition(sf::Vector2f(420.f, 300.f));

    m_difficultyText.setString("Press N for Normal | Press H for Hard");
    m_difficultyText.setCharacterSize(22);
    m_difficultyText.setFillColor(sf::Color(200, 230, 255));
    m_difficultyText.setPosition(sf::Vector2f(330.f, 350.f));

    // Game Over
  
    m_gameOverText.setString("GAME OVER");
    m_gameOverText.setCharacterSize(50);
    m_gameOverText.setFillColor(sf::Color::Red);
    m_gameOverText.setPosition(sf::Vector2f(320.f, 250.f));

    // final score
    
    m_finalScoreText.setCharacterSize(30);
    m_finalScoreText.setFillColor(sf::Color::White);
    m_finalScoreText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 100.f, 350.f));

    m_restartText.setString("Press R to Restart | Press Q to Quit");
    m_restartText.setCharacterSize(22);
    m_restartText.setFillColor(sf::Color(200, 230, 255));
    m_restartText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 250.f, 450.f));

    // button position(center of screen)
    
    float centerX = SCREEN_WIDTH / 2.0f - 150.0f;
    m_titleSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 200.0f, 100.0f));
    m_playSprite.setPosition(sf::Vector2f(centerX, 280.0f));
    m_highscoreSprite.setPosition(sf::Vector2f(centerX, 360.0f));
    m_quitSprite.setPosition(sf::Vector2f(centerX, 440.0f));

    m_gameoverSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 200.0f, 100.0f));
    m_restartBtnSprite.setPosition(sf::Vector2f(centerX, 320.0f));
    m_mainmenuSprite.setPosition(sf::Vector2f(centerX, 400.0f));
    m_quitGoSprite.setPosition(sf::Vector2f(centerX, 480.f));

    //high score button
    m_highscoreTitleSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 200.0f, 150.0f));
    m_quitGoSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 150.0f, 500.0f));

    // difficulty mode choose button
    m_diffTitleSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 200.0f, 150.0f));
    m_normalSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 150.0f, 320.0f));
    m_hardSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 150.0f, 420.0f));

}
// draw update score, final score, and lives

void UI::updateScore(int score)
{
    m_scoreText.setString("Score: " + std::to_string(score));
}

void UI::updateFinalScore(int score) {
    m_finalScoreText.setString("Final Score: " + std::to_string(score));
}

void UI::updateLives(int lives)
{
    m_livesText.setString("Lives: " + std::to_string(lives));
}

//darw score and lives

void UI::drawHUD(sf::RenderWindow& window)
{
    window.draw(m_scoreText);
    window.draw(m_livesText);
}

//draw main menu
void UI::drawMainMenu(sf::RenderWindow& window)
{
    window.draw(m_titleSprite);
    window.draw(m_playSprite);
    window.draw(m_highscoreSprite);
    window.draw(m_quitSprite);
}

// draw gameover menu
void UI::drawGameOver(sf::RenderWindow& window)
{
    window.draw(m_gameoverSprite);
    window.draw(m_finalScoreText);
    window.draw(m_restartBtnSprite);
    window.draw(m_mainmenuSprite);
    window.draw(m_quitGoSprite);
}

// set main menu and game over menu click
int UI::checkMainMenuClick(int mouseX, int mouseY) {
    sf::Vector2f m(static_cast<float>(mouseX), static_cast<float>(mouseY));
    if (m_playSprite.getGlobalBounds().contains(m)) return 1;
    if (m_highscoreSprite.getGlobalBounds().contains(m)) return 2;
    if (m_quitSprite.getGlobalBounds(). contains(m)) return 3;
    return 0;
}

int UI::checkGameOverClick(int mouseX, int mouseY) {
    sf::Vector2f m(static_cast<float>(mouseX), static_cast<float>(mouseY));
    if (m_restartBtnSprite.getGlobalBounds().contains(m)) return 1;
    if (m_mainmenuSprite.getGlobalBounds().contains(m)) return 2;
    if (m_quitGoSprite.getGlobalBounds(). contains(m)) return 3;
    return 0;
}
// draw high score page
void UI::drawHighScorePage(sf::RenderWindow& window, int highScore) {
    window.draw(m_highscoreTitleSprite);
    sf::Text scoreValue(m_font);
    scoreValue.setString("Best: " + std::to_string(highScore));
    scoreValue.setCharacterSize(40);
    scoreValue.setFillColor(sf::Color::White);
    scoreValue.setOutlineColor(sf::Color(100, 70, 20));
    scoreValue.setOutlineThickness(2.0f);
    scoreValue.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f - 100.0f, 320.0f));
    window.draw(scoreValue);
    window.draw(m_backSprite);
}

// draw difficulty mode page and set click
void UI::drawDifficultyPage(sf::RenderWindow& window)
{
    window.draw(m_diffTitleSprite);
    window.draw(m_normalSprite);
    window.draw(m_hardSprite);
}

int UI::checkdifficultyClick(int mouseX, int mouseY) {
    sf::Vector2f m(static_cast<float>(mouseX), static_cast<float>(mouseY));
    if (m_normalSprite.getGlobalBounds().contains(m)) return 1;
    if (m_hardSprite.getGlobalBounds().contains(m)) return 2;
    return 0;
}