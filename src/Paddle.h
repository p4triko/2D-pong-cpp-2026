

#ifndef PONG2D_PADDLE_H
#define PONG2D_PADDLE_H


#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape shape;
    float speed;

public:
    Paddle(sf::Vector2f size, sf::Vector2f position, sf::Color color, float speed);

    void moveUp();
    void moveDown();
    void keepInsideWindow(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;

};


#endif //PONG2D_PADDLE_H