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

    //alt ega ylevalt ei saa kunagi valja minna enam
    void bounceTopBottom(const sf::RenderWindow &window);

    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void reverseX();
    sf::Vector2f getBallPosition();
    void resetBallPosition(sf::Vector2f startPos);
};


#endif //PONG2D_BALL_H