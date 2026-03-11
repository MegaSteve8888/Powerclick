#ifndef HOUSE_HPP
#define HOUSE_HPP
#include <SFML/Graphics.hpp>

class House {
    private:
        sf::RectangleShape;
        float x;
        float y;
        float width;
        float height;
        
    public:
        // constructor
        House();

        //draw house on screen
        void draw(sf::RenderWindow& window);

        //get the house boundaries for collison 
        sf::FloatRect getBounds() const;

        //check if an enemy reached the house
        bool isReached(float enemyX. float enemyY) const;

};


#endif