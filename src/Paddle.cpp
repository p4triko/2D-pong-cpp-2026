
#include "Paddle.h"

Paddle::Paddle(sf::Vector2f size, sf::Vector2f position, sf::Color color, float speed)
    : speed(speed)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Paddle::moveUp()
{
    shape.move({0.f, -speed});
}

void Paddle::moveDown()
{
    shape.move({0.f, speed});
}

void Paddle::keepInsideWindow(const sf::RenderWindow& window)
{
    if (shape.getPosition().y < 0.f)
        shape.setPosition({shape.getPosition().x, 0.f});

    if (shape.getPosition().y + shape.getSize().y > window.getSize().y)
        shape.setPosition({
            shape.getPosition().x,
            static_cast<float>(window.getSize().y) - shape.getSize().y
        });
}

void Paddle::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}
sf::FloatRect Paddle::getBounds() const
{
    return shape.getGlobalBounds();
}