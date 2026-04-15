#include "House.hpp"
#include "Constant.hpp"

//constructor
House::House() : texture("assets/sprites/house.png"), sprite(texture) {
    x = HOUSE_X;
    y = HOUSE_Y;
    width = HOUSE_WIDTH;
    height = HOUSE_HEIGHT;

    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setScale(sf::Vector2f(2.0f, 2.0f));
  
}

// draw the house on the window
void House::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

//get boundaries for collision detection
sf::FloatRect House::getBounds() const {
    return sprite.getGlobalBounds();
}

//check if an enemy position has reached the house
bool House::isReached(float enemyX, float enemyY) const {
    return (enemyX >= x && enemyX <= x + width && enemyY >= y && enemyY <= y + height);
}
