#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({1000, 720}), "2D Pong");
	window.setFramerateLimit(67); //hehe

	Paddle leftPlayer(
		{30.f, 120.f},
		{10.f, 300.f},
		sf::Color::Green,
		5.f
		);

	Paddle rightPlayer(
		{30.f, 120.f},
		{960.f, 300.f},
		sf::Color::Red,
		5.f
		);

	Ball ball(
		10.f,
		{500.f, 360.f},
		{4.f, 4.f}
		);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
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

		window.clear();
		leftPlayer.draw(window);
		rightPlayer.draw(window);
		ball.draw(window);
		window.display();
	}
}