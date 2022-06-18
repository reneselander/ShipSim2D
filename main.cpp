#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "entity.h"

int main()

{


	sf::RenderWindow window(sf::VideoMode(1200, 1080), "Ship Sim V 0.2.2.6", sf::Style::Default);

	window.setFramerateLimit(60);

	sf::Event event;

	// Startpositionen för fartyget
	entity player(window.getSize().x / 4, window.getSize().y / 4);

	// Skapa en holme
	sf::RectangleShape holme1;
	holme1.setFillColor(sf::Color(0, 153, 76));

	// Bestäm storleken på holme 1, i pixlar
	holme1.setSize(sf::Vector2f(60, 60));

	// Skapa start-positionen för holme 1, 
	sf::Vector2f rectanglePosition(300, 300);
	holme1.setPosition(rectanglePosition);


	sf::RectangleShape holme2;
	holme2.setFillColor(sf::Color(0, 102, 0));

	// Bestäm storleken på holme 2, i pixlar
	holme2.setSize(sf::Vector2f(40, 40));

	// Skapa start-positionen för holme 2, 
	sf::Vector2f rectanglePosition2(600, 500);
	holme2.setPosition(rectanglePosition2);

	sf::RectangleShape holme3;
	holme3.setFillColor(sf::Color(0, 182, 0));

	// Bestäm storleken på holme 2, i pixlar
	holme3.setSize(sf::Vector2f(40, 30));

	// Skapa start-positionen för holme 2, 
	sf::Vector2f holmePosition3(700, 100);
	holme3.setPosition(holmePosition3);
	

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
		window.draw(holme1);
		window.draw(holme2);
		window.draw(holme3);


		player.drawTo(window);
		
		window.display();
	
	}

}