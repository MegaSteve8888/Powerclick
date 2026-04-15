#include <SFML/Graphics.hpp>
#include "House.hpp"
#include "Player.hpp"
#include "Constant.hpp"
#include "Enemy.h"
#include "Utilities.hpp"
#include "AudioManager.hpp"
#include <vector>
#include <ctime>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), GAME_TITLE);
    window.setFramerateLimit(FRAME_RATE);
    sf::Texture bgTexture("assets/sprites/background.png");
    sf::Sprite bgSprite(bgTexture);
    //scale the background to fill the window
    bgSprite.setScale(sf::Vector2f((float)SCREEN_WIDTH / bgTexture.getSize().x, (float)SCREEN_HEIGHT / bgTexture.getSize().y));

    House house;
    Player player;
    AudioManager audio;
    audio.init();
    audio.playBGM();

    sf::Font font;
    if (!font.loadFromFile(getAssetPath("assets/fonts/arial.ttf"))) {
        // Handle font load failure here if needed
    }

    sf::Text scoreText("Score: 0", font, 20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(10.0f, 10.0f));

    srand(time(0));
    std::vector<Enemy> enemies;
    sf::Clock spawnClock;
    float spawnInterval = 1.5f;
    sf::Clock gameClock;
    sf::Texture enemyTexture("assets/sprites/enemy.png");

    sf::Text livesText("Lives: 3", font, 20);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(sf::Vector2f(10.0f, 40.0f));

    while (window.isOpen()) {
<<<<<<< Updated upstream
        float dt = gameClock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Button::Left) {
                    for (int i = enemies.size() - 1; i >= 0; i--) {
                        if (enemies[i].isClicked(event.mouseButton.x, event.mouseButton.y)) {
                            enemies.erase(enemies.begin() + i);
                            player.addScore(POINTS_PER_KILL);
                            break;
                        }
=======
       float dt = gameClock.restart().asSeconds();
       while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
        if (const auto*mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                for (int i = enemies.size() - 1; i >= 0; i--) {
                    if (enemies[i].isClicked(mousePressed->position.x, mousePressed->position.y)) {
                        enemies.erase(enemies.begin() + i);
                        player.addScore(POINTS_PER_KILL);
                        audio.playClick();
                        break;
>>>>>>> Stashed changes
                    }
                }
            }
        }

        // Spawn enemies implement
        if (spawnClock.getElapsedTime().asSeconds() > spawnInterval) {
            int side = randomInt(0, 3);
            float startX, startY;
            if (side == 0) {
                startX = randomInt(0, SCREEN_WIDTH);
                startY = -20;
            }
            else if (side == 1) {
                startX = randomInt(0, SCREEN_WIDTH);
                startY = SCREEN_HEIGHT + 20;
            }
            else if (side == 2) {
                startX = -20;
                startY = randomInt(0, SCREEN_HEIGHT);
            }
            else {
                startX = SCREEN_WIDTH + 20;
                startY = randomInt(0, SCREEN_HEIGHT);
            }
<<<<<<< Updated upstream

            // Temporary fast enemy spawning logic for testing.
            bool fastEnemy = (randomInt(1, FAST_ENEMY_SPAWN_CHANCE) == 1);
            float enemySpeed = ENEMY_BASE_SPEED * 60.0f;
            Enemy::Type type = Enemy::Type::Normal;
            if (fastEnemy) {
                enemySpeed *= FAST_ENEMY_SPEED_MULTIPLIER;
                type = Enemy::Type::Fast;
            }

            enemies.push_back(Enemy(startX, startY, enemySpeed, enemyTexture, type));
=======
            enemies.push_back(Enemy(startX, startY, ENEMY_BASE_SPEED * 60.0f, enemyTexture));
>>>>>>> Stashed changes
            spawnClock.restart();
        }

        // update enemies
        sf::Vector2f houseCenter(HOUSE_X + HOUSE_WIDTH / 2, HOUSE_Y + HOUSE_HEIGHT / 2);
        for (int i = enemies.size() - 1; i >= 0; i--) {
            enemies[i].update(dt, houseCenter);
            if (enemies[i].hasReachedTarget(houseCenter)) {
                enemies.erase(enemies.begin() + i);
                player.loseLife();
                audio.playHit();
            }
        }

        // Check game over
        if (!player.isAlive()) {
            audio.playGameOver();
            break;
        }

        // Draw
        window.clear(sf::Color(30, 30, 50));
        window.draw(bgSprite);
        house.draw(window);

        for (auto& enemy : enemies) {
            enemy.render(window);
        }
        scoreText.setString("Score: " + std::to_string(player.getScore()));
        livesText.setString("Lives: " + std::to_string(player.getLives()));
        window.draw(scoreText);
        window.draw(livesText);

        window.display();
    }
    return 0;
}