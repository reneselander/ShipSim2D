#pragma once
#include <SFML/Graphics.hpp>




class entity
{
public:
	entity(float x, float y)
	{
		/*ship.setFillColor(sf::Color(112, 130, 56));
		//sf::Vector2f(x, y)
		ship.setSize(sf::Vector2f(100, 40));*/

		ship.setRadius(30.f);
		ship.setPointCount(3);
		ship.setFillColor(sf::Color::White);
		ship.setOutlineThickness(4.f);
		ship.setOutlineColor(sf::Color::Black);
		ship.setRotation(90.0);
		
		up = false;
		down = false;
		left = false;
		right = false;
	}




	void processEvents(sf::Keyboard::Key key, bool checkPressed)
	{

		if (checkPressed == true)
		{
			if (key == sf::Keyboard::Up)
				up = true;
			if (key == sf::Keyboard::Down)
				down = true;
			if (key == sf::Keyboard::Left)
				left = true;
			if (key == sf::Keyboard::Right)
				right = true;
		}

		if (checkPressed == false)
		{
			up = false;
			down = false;
			left = false;
			right = false;
		}

	}

	void update()
	{
		sf::Vector2f movement;
		if (up)
			movement.y -= 1.0f;
		if (down)
			movement.y += 1.0f;
		if (left)
			movement.x -= 1.0f;
		if (right)
			movement.x += 1.0f;
		ship.move(movement);

	}

	void drawTo(sf::RenderWindow &window)
	{
		window.draw(ship);
	}
private:
	sf::CircleShape ship;
	bool up;
	bool down;
	bool left;
	bool right;
};