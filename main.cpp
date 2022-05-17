#include <iostream>
#include <SFML/Graphics.hpp>

#include "entity.h"

int main()

{

	sf::RenderWindow window(sf::VideoMode(1200, 1080), "Ship Sim V 0.2.2.4", sf::Style::Default);

	window.setFramerateLimit(60);

	sf::Event event;

	//window.getSize().x/4, window.getSize().y/4
	entity player(window.getSize().x / 4, window.getSize().y / 4);

	// Skapa en holme
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(0, 153, 76));

	// Bestäm storleken på box 1, i pixlar
	rect.setSize(sf::Vector2f(60, 60));

	// Skapa start-positionen för box 1, 
	sf::Vector2f rectanglePosition(300, 300);
	rect.setPosition(rectanglePosition);

	

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				player.processEvents(event.key.code, true);

			if (event.type == sf::Event::KeyReleased)
				player.processEvents(event.key.code, false);
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				window.close();

			

			
			
		}
		window.clear(sf::Color(135, 206, 250, 0.2));
		player.update();
		window.draw(rect);
		player.drawTo(window);
		window.display();
	}













}