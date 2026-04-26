
#ifndef PONG2D_BALL_H
#define PONG2D_BALL_H

#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Ball(float radius, sf::Vector2f velocity, sf::Vector2f position);
    void update();

    void bounceTopBottom(const sf::RenderWindow &window);

    //alt ega ylevalt ei saa kunagi valja minna enam
    void BounceTopBottom(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void reverseX();
};


#endif //PONG2D_BALL_H