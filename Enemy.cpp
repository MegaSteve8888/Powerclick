#include "Enemy.h"
#include <cmath>

Enemy::Enemy(float startX, float startY, float speed)
    : m_speed(speed)
{
    m_shape.setRadius(20.f);
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(startX, startY);
}

void Enemy::update(float dt, sf::Vector2f targetPosition)
{
    sf::Vector2f currentPos = m_shape.getPosition();

    float dx = targetPosition.x - currentPos.x;
    float dy = targetPosition.y - currentPos.y;
    float length = std::sqrt(dx * dx + dy * dy);

    if (length != 0.f)
    {
        dx /= length;
        dy /= length;

        m_shape.move(dx * m_speed * dt, dy * m_speed * dt);
    }
}

void Enemy::render(sf::RenderWindow& window) const
{
    window.draw(m_shape);
}

bool Enemy::isClicked(int mouseX, int mouseY) const
{
    return m_shape.getGlobalBounds().contains(
        static_cast<float>(mouseX),
        static_cast<float>(mouseY)
    );
}

bool Enemy::hasReachedTarget(sf::Vector2f targetPosition) const
{
    sf::Vector2f currentPos = m_shape.getPosition();

    float dx = targetPosition.x - currentPos.x;
    float dy = targetPosition.y - currentPos.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < 25.f;
}

sf::Vector2f Enemy::getPosition() const
{
    return m_shape.getPosition();
}

sf::FloatRect Enemy::getBounds() const
{
    return m_shape.getGlobalBounds();
}
