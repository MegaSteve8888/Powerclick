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
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color(30, 30, 50));

        house.draw(window);

        scoreText.setString("score: " + std::to_string(player.getScore()));
        LivesText.setString("lives: " + std::to_string(player.getLives()));
        window.draw(scoreText);
        window.draw(LivesText);

        window.display();
    }
    return 0;
}