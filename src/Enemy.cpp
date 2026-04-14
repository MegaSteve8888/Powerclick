#include "Enemy.h"
#include "Utilities.hpp"
#include <cmath>

Enemy::Enemy(float startX, float startY, float speed)
    : m_speed(speed)
{
    if (!m_texture.loadFromFile(getAssetPath("assets/sprites/enemy.png"))) {
        // Handle texture load failure if needed
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(sf::Vector2f(startX, startY));
    m_sprite.setScale(sf::Vector2f(2.0f, 2.0f));
}

void Enemy::update(float dt, sf::Vector2f targetPosition)
{
    sf::Vector2f currentPos = m_sprite.getPosition();

    float dx = targetPosition.x - currentPos.x;
    float dy = targetPosition.y - currentPos.y;
    float length = std::sqrt(dx * dx + dy * dy);

    if (length != 0.f)
    {
        dx /= length;
        dy /= length;

        m_sprite.move(sf::Vector2f(dx * m_speed * dt, dy * m_speed * dt));
    }
}

void Enemy::render(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}

bool Enemy::isClicked(int mouseX, int mouseY) const
{
    return m_sprite.getGlobalBounds().contains(
        sf::Vector2f(static_cast<float>(mouseX), static_cast<float>(mouseY))
    );
}

bool Enemy::hasReachedTarget(sf::Vector2f targetPosition) const
{
    sf::Vector2f currentPos = m_sprite.getPosition();

    float dx = targetPosition.x - currentPos.x;
    float dy = targetPosition.y - currentPos.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < 25.f;
}

sf::Vector2f Enemy::getPosition() const
{
    return m_sprite.getPosition();
}

sf::FloatRect Enemy::getBounds() const
{
    return m_sprite.getGlobalBounds();
}
