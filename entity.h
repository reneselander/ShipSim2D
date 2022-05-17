#pragma once
#include <SFML/Graphics.hpp>

class entity
{
public:
	entity(float x, float y)
	{
		rect.setFillColor(sf::Color(112, 130, 56));
		//sf::Vector2f(x, y)
		rect.setSize(sf::Vector2f(180, 80));
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
		rect.move(movement);

	}

	void drawTo(sf::RenderWindow &window)
	{
		window.draw(rect);
	}
private:
	sf::RectangleShape rect;
	bool up;
	bool down;
	bool left;
	bool right;
};