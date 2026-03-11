#include <SFML/Graphics.hpp>
#include "House.hpp"
#include "Player.hpp"
#include "Constants.hpp"
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), GAME_TITLE);
    window.setFramerateLimit(FRAME_RATE);

    House house;
    Player player;

    sf::Front front("assets/fonts/arial.ttf");

    sf::Text scoreText(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::white);
    scoreText.setPosition(sf::Vector2f(10.0f, 10.0f));

    sf::Text LivesText(font);
    LivesText.setCharacterSize(20);
    LivesText.setFillColor(sf::Color::White);
    LivesText.setPosition(sf::Vector2f(10.0f, 40.0f));
    
    
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color(50, 50, 80));
        window.display();
    }
    return 0;
}