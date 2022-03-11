#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>


class Obstacles
{
private:
	std::vector<sf::RectangleShape> boxes;
	float width = 50;
	float height = 50;

	bool obstaclesGenerated = false;
public:
	bool mapGenerated = false;
	Obstacles();
	Obstacles(bool _generateObstacles, bool _generateMap);
	void Draw(sf::RenderWindow &window);
	bool CheckForCollision(sf::Vector2f position);
	bool isOnMap();

};

Obstacles::Obstacles()
{

}

Obstacles::Obstacles(bool _generateObstacles, bool _generateMap)
{
	obstaclesGenerated = _generateObstacles;
	mapGenerated = _generateMap;

	if (_generateObstacles == true)
	{
		for (int i = 0; i < 10; i++)
		{
			sf::RectangleShape box(sf::Vector2f(width, height));
			box.setOrigin(sf::Vector2f(width / 2, height / 2));
			boxes.push_back(box);
		}

		boxes[0].setPosition(sf::Vector2f(600, 250));
		boxes[1].setPosition(sf::Vector2f(500, 100));
		boxes[2].setPosition(sf::Vector2f(400, 300));
		boxes[3].setPosition(sf::Vector2f(600, 560));
		boxes[4].setPosition(sf::Vector2f(300, 700));
		boxes[5].setPosition(sf::Vector2f(720, 750));
		boxes[6].setPosition(sf::Vector2f(50, 600));
		boxes[7].setPosition(sf::Vector2f(65, 450));
		boxes[8].setPosition(sf::Vector2f(70, 100));
		boxes[9].setPosition(sf::Vector2f(250, 150));
	}

	if (_generateMap == true)
	{
		for (int i = 0; i < 188; i++)
		{
			sf::RectangleShape box(sf::Vector2f(width, height));
			box.setOrigin(sf::Vector2f(width / 2, height / 2));
			boxes.push_back(box);
		}

		// Map creation - Places blocks (messy code)
		for (int i = 0; i < 16; i++)
		{
			boxes[i].setPosition(sf::Vector2f(50 * i + 25, 25));
		}

		for (int i = 0; i < 16; i++)
		{
			boxes[i + 16].setPosition(sf::Vector2f(25, 50 * i + 25));
		}

		for (int i = 0; i < 16; i++)
		{
			boxes[i + 32].setPosition(sf::Vector2f(775, 50 * i + 25));
		}

		for (int i = 0; i < 16; i++)
		{	
			boxes[i + 48].setPosition(sf::Vector2f(50 * i + 25, 775));
		}

		int index = 64;
		boxes[index++].setPosition(sf::Vector2f(550, 50));
		boxes[index++].setPosition(sf::Vector2f(600, 75));
		boxes[index++].setPosition(sf::Vector2f(650, 75));
		boxes[index++].setPosition(sf::Vector2f(700, 75));
		boxes[index++].setPosition(sf::Vector2f(750, 75));
		boxes[index++].setPosition(sf::Vector2f(650, 125));
		boxes[index++].setPosition(sf::Vector2f(700, 125));
		boxes[index++].setPosition(sf::Vector2f(650, 50));
		boxes[index++].setPosition(sf::Vector2f(700, 175));
		boxes[index++].setPosition(sf::Vector2f(650, 300));
		boxes[index++].setPosition(sf::Vector2f(600, 280));
		boxes[index++].setPosition(sf::Vector2f(750, 250));
		boxes[index++].setPosition(sf::Vector2f(750, 200));
		boxes[index++].setPosition(sf::Vector2f(750, 150));
		boxes[index++].setPosition(sf::Vector2f(650, 450));
		boxes[index++].setPosition(sf::Vector2f(650, 400));
		boxes[index++].setPosition(sf::Vector2f(650, 350));

		boxes[index++].setPosition(sf::Vector2f(600, 450));
		boxes[index++].setPosition(sf::Vector2f(600, 400));
		boxes[index++].setPosition(sf::Vector2f(600, 350));
		boxes[index++].setPosition(sf::Vector2f(600, 300));

		boxes[index++].setPosition(sf::Vector2f(550, 450));
		boxes[index++].setPosition(sf::Vector2f(550, 400));
		boxes[index++].setPosition(sf::Vector2f(550, 350));
		boxes[index++].setPosition(sf::Vector2f(550, 300));
		boxes[index++].setPosition(sf::Vector2f(550, 250));

		boxes[index++].setPosition(sf::Vector2f(500, 450));
		boxes[index++].setPosition(sf::Vector2f(500, 400));
		boxes[index++].setPosition(sf::Vector2f(500, 350));
		boxes[index++].setPosition(sf::Vector2f(500, 300));
		boxes[index++].setPosition(sf::Vector2f(500, 250));

		boxes[index++].setPosition(sf::Vector2f(450, 400));
		boxes[index++].setPosition(sf::Vector2f(450, 350));
		boxes[index++].setPosition(sf::Vector2f(450, 300));
		boxes[index++].setPosition(sf::Vector2f(450, 250));

		boxes[index++].setPosition(sf::Vector2f(400, 400));
		boxes[index++].setPosition(sf::Vector2f(400, 350));
		boxes[index++].setPosition(sf::Vector2f(400, 300));
		boxes[index++].setPosition(sf::Vector2f(400, 250));

		boxes[index++].setPosition(sf::Vector2f(350, 400));
		boxes[index++].setPosition(sf::Vector2f(350, 350));
		boxes[index++].setPosition(sf::Vector2f(350, 300));

		boxes[index++].setPosition(sf::Vector2f(300, 400));
		boxes[index++].setPosition(sf::Vector2f(300, 350));
		boxes[index++].setPosition(sf::Vector2f(300, 300));

		boxes[index++].setPosition(sf::Vector2f(250, 400));
		boxes[index++].setPosition(sf::Vector2f(250, 350));
		boxes[index++].setPosition(sf::Vector2f(250, 300));
		boxes[index++].setPosition(sf::Vector2f(250, 425));

		boxes[index++].setPosition(sf::Vector2f(200, 450));
		boxes[index++].setPosition(sf::Vector2f(200, 400));
		boxes[index++].setPosition(sf::Vector2f(200, 350));
		boxes[index++].setPosition(sf::Vector2f(200, 300));

		boxes[index++].setPosition(sf::Vector2f(150, 450));
		boxes[index++].setPosition(sf::Vector2f(150, 400));
		boxes[index++].setPosition(sf::Vector2f(150, 350));
		boxes[index++].setPosition(sf::Vector2f(150, 300));


		//boxes[index++].setPosition(sf::Vector2f(650, 450));


		boxes[index++].setPosition(sf::Vector2f(750, 100));
		boxes[index++].setPosition(sf::Vector2f(750, 600));
		boxes[index++].setPosition(sf::Vector2f(750, 650));
		boxes[index++].setPosition(sf::Vector2f(750, 700));
		boxes[index++].setPosition(sf::Vector2f(750, 750));
		boxes[index++].setPosition(sf::Vector2f(750, 750));
		boxes[index++].setPosition(sf::Vector2f(700, 750));
		boxes[index++].setPosition(sf::Vector2f(500, 750));
		boxes[index++].setPosition(sf::Vector2f(450, 700));
		boxes[index++].setPosition(sf::Vector2f(450, 650));
		boxes[index++].setPosition(sf::Vector2f(450, 600));
		boxes[index++].setPosition(sf::Vector2f(450, 550));
		boxes[index++].setPosition(sf::Vector2f(450, 400));
		boxes[index++].setPosition(sf::Vector2f(500, 450));
		boxes[index++].setPosition(sf::Vector2f(525, 475));
		boxes[index++].setPosition(sf::Vector2f(550, 550));
		boxes[index++].setPosition(sf::Vector2f(550, 550));
		boxes[index++].setPosition(sf::Vector2f(600, 550));
		boxes[index++].setPosition(sf::Vector2f(600, 500));
		boxes[index++].setPosition(sf::Vector2f(550, 500));
		boxes[index++].setPosition(sf::Vector2f(575, 600));
		boxes[index++].setPosition(sf::Vector2f(575, 650));

		boxes[index++].setPosition(sf::Vector2f(450, 750));

		boxes[index++].setPosition(sf::Vector2f(400, 550));
		boxes[index++].setPosition(sf::Vector2f(400, 600));
		boxes[index++].setPosition(sf::Vector2f(400, 650));
		boxes[index++].setPosition(sf::Vector2f(400, 700));
		boxes[index++].setPosition(sf::Vector2f(400, 750));

		boxes[index++].setPosition(sf::Vector2f(350, 550));
		boxes[index++].setPosition(sf::Vector2f(350, 600));
		boxes[index++].setPosition(sf::Vector2f(350, 650));
		boxes[index++].setPosition(sf::Vector2f(350, 700));
		boxes[index++].setPosition(sf::Vector2f(350, 750));

		boxes[index++].setPosition(sf::Vector2f(300, 550));
		boxes[index++].setPosition(sf::Vector2f(300, 600));
		boxes[index++].setPosition(sf::Vector2f(300, 650));
		boxes[index++].setPosition(sf::Vector2f(300, 700));
		boxes[index++].setPosition(sf::Vector2f(300, 750));

		boxes[index++].setPosition(sf::Vector2f(250, 550));
		boxes[index++].setPosition(sf::Vector2f(250, 600));
		boxes[index++].setPosition(sf::Vector2f(250, 650));
		boxes[index++].setPosition(sf::Vector2f(250, 700));
		boxes[index++].setPosition(sf::Vector2f(250, 750));

		boxes[index++].setPosition(sf::Vector2f(200, 550));
		boxes[index++].setPosition(sf::Vector2f(200, 600));
		boxes[index++].setPosition(sf::Vector2f(200, 650));
		boxes[index++].setPosition(sf::Vector2f(200, 700));
		boxes[index++].setPosition(sf::Vector2f(200, 750));

		boxes[index++].setPosition(sf::Vector2f(150, 550));
		boxes[index++].setPosition(sf::Vector2f(150, 600));
		boxes[index++].setPosition(sf::Vector2f(150, 650));
		boxes[index++].setPosition(sf::Vector2f(150, 700));
		boxes[index++].setPosition(sf::Vector2f(150, 750));

		boxes[index++].setPosition(sf::Vector2f(100, 550));
		boxes[index++].setPosition(sf::Vector2f(100, 600));
		boxes[index++].setPosition(sf::Vector2f(100, 650));
		boxes[index++].setPosition(sf::Vector2f(100, 700));
		boxes[index++].setPosition(sf::Vector2f(100, 750));

		boxes[index++].setPosition(sf::Vector2f(50, 550));
		boxes[index++].setPosition(sf::Vector2f(50, 600));
		boxes[index++].setPosition(sf::Vector2f(50, 650));
		boxes[index++].setPosition(sf::Vector2f(50, 700));
		boxes[index++].setPosition(sf::Vector2f(50, 750));

		boxes[index++].setPosition(sf::Vector2f(50, 525));

		boxes[index++].setPosition(sf::Vector2f(50, 75));
		boxes[index++].setPosition(sf::Vector2f(50, 125));
		boxes[index++].setPosition(sf::Vector2f(100, 75));
	}
}

void Obstacles::Draw(sf::RenderWindow &window)
{
	if (this->obstaclesGenerated == false && this->mapGenerated == false)
	{
		return;
	}

	for (int i = 0; i < boxes.size(); i++)
	{
		window.draw(boxes[i]);
	}
}

bool Obstacles::CheckForCollision(sf::Vector2f position)
{
	if (this->obstaclesGenerated == false && this->mapGenerated == false)
	{
		return false;
	}

	for (int i = 0; i < boxes.size(); i++)
	{
		sf::Vector2f boxPosition = boxes[i].getPosition();
		if ((position.x >= boxPosition.x - this->width / 2 && position.x <= boxPosition.x + this->width / 2 && position.y >= boxPosition.y - this->height / 2 && position.y <= boxPosition.y + this->height / 2))
		{
			return true;
		}
	}
	return false;
}