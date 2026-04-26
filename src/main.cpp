#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({1000, 720}), "2D Pong");
	window.setFramerateLimit(60);

	sf::RectangleShape player({30.f, 120.f});
	player.setPosition({10.f, static_cast<float>(window.getSize().y / 2.f)});
	player.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				player.move({0.f, -1.f});
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.move({0.f, 1.f});
			}
		}

		window.clear();
		window.draw(player);
		window.display();
	}
}
