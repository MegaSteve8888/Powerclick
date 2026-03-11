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