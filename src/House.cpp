#include "House.hpp"
#include "Constant.hpp"

//constructor
House::House() {
    x = HOUSE_X;
    y = HOUSE_Y;
    width = HOUSE_WIDTH;
    height = HOUSE_HEIGHT;

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(sf::Color(70, 130, 180));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.0f);
}

// draw the house on the window
void House::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

//get boundaries for collision detection
sf::FloatRect House::getBounds() const {
    return shape.getGlobalBounds();
}

//check if an enemy position has reached the house
bool House::isReached(float enemyX, float enemyY) const {
    return (enemyX >= x && enemyX <= x + width && enemyY >= y && enemyY <= y + height);
}
