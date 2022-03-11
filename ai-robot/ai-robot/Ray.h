#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacles.h"

class Ray
{
private:
	float distance;
	float relativePosition;

	sf::Vertex line[2];

	sf::Vector2f lineRelativePosition;
	sf::Vector2f distanceVector;

	Obstacles* obs;
public:
	float distanceNorm;
	Ray();
	Ray(float _distance, float _angle, sf::Vector2f& _robotPosition, sf::Vector2f _relativePosition, Obstacles& _obstacles);
	void Update(sf::Vector2f& _robotPosition, sf::Vector2f _relativePosition, float robotAngle);
	void Draw(sf::RenderWindow &window);
};

Ray::Ray()
{

}

Ray::Ray(float _distance, float _angle, sf::Vector2f& _robotPosition, sf::Vector2f _relativePosition, Obstacles& _obstacles)
{
	obs = &_obstacles;

	// Place distance sensor root and end point
	distance = _distance;
	line[0] = sf::Vertex(_robotPosition + _relativePosition);
	line[1] = sf::Vertex(_robotPosition + _relativePosition + sf::Vector2f(30, 30));
	line->color = sf::Color::Red;

	lineRelativePosition = distance * sf::Vector2f(std::cos(deg2rad(_angle + 90)), std::sin(deg2rad(_angle + 90)));
}

void Ray::Draw(sf::RenderWindow &window)
{
	window.draw(line, 2, sf::Lines);
}

void Ray::Update(sf::Vector2f& _robotPosition, sf::Vector2f _relativePosition, float robotAngle)
{
	// Update sensor positions
	line[0].position = sf::Vector2f(_robotPosition.x + (_relativePosition.x * std::cos(deg2rad(robotAngle)) - _relativePosition.y * std::sin(deg2rad(robotAngle))), _robotPosition.y + (_relativePosition.x * std::sin(deg2rad(robotAngle)) + _relativePosition.y * std::cos(deg2rad(robotAngle))));
	line[1].position = sf::Vector2f(line[0].position.x + (lineRelativePosition.x * std::cos(deg2rad(robotAngle)) - lineRelativePosition.y * std::sin(deg2rad(robotAngle))), line[0].position.y + (lineRelativePosition.x * std::sin(deg2rad(robotAngle)) + lineRelativePosition.y * std::cos(deg2rad(robotAngle))));

	// Create a linear interpolation between the two points to find where there can be a collision
	for (float t = 0; t <= 1.05; t += 0.1f)
	{
		sf::Vector2f checkPoint = line[0].position + t * (line[1].position - line[0].position);

		sf::Vector2f circleCenter(400, 400);
		float circleRadius = 400;

		if (obs->CheckForCollision(checkPoint))
		{
			distanceNorm = t;
			break;
		}

		if (checkPoint.x > 800 || checkPoint.x < 0 || checkPoint.y < 0 || checkPoint.y > 800)
		{
			distanceNorm = t;
			break;
		}

		distanceNorm = 1;
	}	
}

