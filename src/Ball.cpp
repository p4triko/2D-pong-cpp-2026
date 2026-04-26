#include "Ball.h"

Ball::Ball(float radius, sf::Vector2f position, sf::Vector2f velocity)
    : velocity(velocity)
{
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::White);
}

void Ball::update()
{
    shape.move(velocity);
}

void Ball::bounceTopBottom(const sf::RenderWindow &window)
{
    if (shape.getPosition().y < 0.f ||
        shape.getPosition().y + shape.getRadius() * 2 > window.getSize().y)
    {
        velocity.y = -velocity.y;
    }
}

void Ball::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::FloatRect Ball::getBounds() const
{
    return shape.getGlobalBounds();
}

void Ball::reverseX()
{
    velocity.x = -velocity.x;
}

sf::Vector2f Ball::getBallPosition()
{
    return shape.getPosition();
}

void Ball::resetBallPosition(sf::Vector2f startPos){
    shape.setPosition(startPos);
}
