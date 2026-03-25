#include <SFML/Graphics.hpp>
#include "House.hpp"
#include "Player.hpp"
#include "Constant.hpp"
#include "Enemy.h"
#include "Utilities.hpp"
#include <vector>
#include <ctime>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), GAME_TITLE);
    window.setFramerateLimit(FRAME_RATE);

    House house;
    Player player;

    sf::Font front("assets/fonts/arial.ttf");

    sf::Text scoreText(front);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(10.0f, 10.0f));

    srand(time(0));
    std::vector<Enemy> enemies;
    sf::Clock spawnClock;
    float spawnInterval = 1.5f;
    sf::Clock gameClock;

    sf::Text LivesText(front);
    LivesText.setCharacterSize(20);
    LivesText.setFillColor(sf::Color::White);
    LivesText.setPosition(sf::Vector2f(10.0f, 40.0f));

    
    while (window.isOpen()) {
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
                        break;
                    }
                }
            }
        }
        // Spawn enemies implement
        if(spawnClock.getElapsedTime().asSeconds() > spawnInterval) {
            int side = randomInt(0, 3);
            float startX, startY;
            if (side == 0) {
                startX = randomInt(0, SCREEN_WIDTH); startY = -20; 
                }
            else if (side ==1) {
                startX = randomInt(0, SCREEN_WIDTH); startY = SCREEN_HEIGHT + 20;
            }
            else if (side == 2) {
                startX = -20; startY = randomInt(0, SCREEN_HEIGHT);
            }
            else {
                startX = SCREEN_WIDTH + 20; startY = randomInt(0, SCREEN_HEIGHT);
            }
            enemies.push_back(Enemy(startX, startY, ENEMY_BASE_SPEED * 60.0f));
            spawnClock.restart();
        }
        // update enemies
        sf::Vector2f houseCenter(HOUSE_X + HOUSE_WIDTH / 2, HOUSE_Y + HOUSE_HEIGHT / 2);
        for (int i = enemies.size() - 1; i >= 0; i--) {
            enemies[i].update(dt, houseCenter);
            if (enemies[i].hasReachedTarget(houseCenter)) {
                enemies.erase(enemies.begin() + i);
                player.loseLife();
            }
        }
        // Check game over
        if (!player.isAlive()) {
            break;
        }
        // Draw
        window.clear(sf::Color(30, 30, 50));
        house.draw(window);

        for (auto& enemy : enemies) {
            enemy.render(window);
        }
        scoreText.setString("Score: " + std::to_string(player.getScore()));
        LivesText.setString("Lives: " + std::to_string(player.getLives()));
        window.draw(scoreText);
        window.draw(LivesText);

        window.display();
        }
    }
    return 0;
}