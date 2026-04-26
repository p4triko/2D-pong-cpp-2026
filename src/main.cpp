#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include <iostream>

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 720;
const sf::Vector2f BALL_START_POS = {500.f, 360.f};

int main()
{
	sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "2D Pong");
	window.setFramerateLimit(60);

	Paddle leftPlayer(
		{30.f, 120.f},
		{10.f, 300.f},
		sf::Color::Green,
		5.f);

	Paddle rightPlayer(
		{30.f, 120.f},
		{960.f, 300.f},
		sf::Color::Red,
		5.f);

	Ball ball(
		10.f,
		BALL_START_POS,
		{4.f, 4.f});

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			leftPlayer.moveUp();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			leftPlayer.moveDown();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			rightPlayer.moveUp();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			rightPlayer.moveDown();

		leftPlayer.keepInsideWindow(window);
		rightPlayer.keepInsideWindow(window);

		ball.update();
		ball.bounceTopBottom(window);

		if (ball.getBounds().findIntersection(leftPlayer.getBounds()).has_value())
			ball.reverseX();
		if (ball.getBounds().findIntersection(rightPlayer.getBounds()).has_value())
			ball.reverseX();

		//std::cout << "x: " << ball.getBallPosition().x << " " << "y: " << ball.getBallPosition().y << '\n';

		if (ball.getBallPosition().x < -40.f)
		{
			std::cout << "Right side scored!" << '\n';
			ball.resetBallPosition(BALL_START_POS);
			ball.reverseX();
		}

		if (ball.getBallPosition().x > 1040.f)
		{
			std::cout << "Left side scored!" << '\n';
			ball.resetBallPosition(BALL_START_POS);
			ball.reverseX();
		}

		window.clear();
		leftPlayer.draw(window);
		rightPlayer.draw(window);
		ball.draw(window);
		window.display();
	}
}