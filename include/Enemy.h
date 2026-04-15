#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    enum class Type {Normal, Fast };
    Enemy(float startX, float startY, float speed, const sf::Texture &texture, Type type = Type::Normal);
    void update(float dt, sf::Vector2f targetPosition);
    void render(sf::RenderWindow& window) const;

    bool isClicked(int mouseX, int mouseY) const;
    bool hasReachedTarget(sf::Vector2f targetPosition) const;

    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;

private:
    sf::Sprite m_sprite;
    float m_speed;
    Type m_type;
};
