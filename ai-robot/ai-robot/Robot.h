#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "math.h"
#include "Ray.h"
#include "Perceptron.h"
#include "Obstacles.h"

class Robot
{
private:
	// Transform
	sf::Vector2f position;
	float currentAngle;
	sf::Vector2f forwardVector;

	// Graphical information
	sf::RectangleShape body;

	// Rays
	Ray leftRay;
	Ray rightRay;

	// Controls
	float speed = 70;
	bool manualControl = true;
	void Move(float &deltaTime);
	void Rotate(float angle);

	// Perceptrons
	Perceptron leftMotorPerceptron;

	// Map knowledge
	Obstacles* obs;

	void spawn();

public:
	Robot();
	Robot(sf::Vector2f _position, float _angle, float w1, float w2, bool _manualControl, int _speed, Obstacles& _obstacles);

	void Draw(sf::RenderWindow& window);
	void Update(float& deltaTime);
	void Input(float& deltaTime);
};

Robot::Robot()
{

};

Robot::Robot(sf::Vector2f _position, float _angle, float w1, float w2, bool _manualControl, int _speed, Obstacles& _obstacles)
{
	// Prepare robot
	manualControl = _manualControl;
	obs = &_obstacles;
	speed = _speed;

	this->currentAngle = _angle;
	this->forwardVector = sf::Vector2f(std::cos(deg2rad(currentAngle + 90)), std::sin(deg2rad(currentAngle + 90)));

	this->body.setSize(sf::Vector2f(25, 50));
	this->body.setOrigin(sf::Vector2f(12.5f, 25.0f));

	spawn();

	this->body.setPosition(this->position);
	this->body.setRotation(this->currentAngle);

	// Create distance sensors
	leftRay = Ray(40, -20, this->position, sf::Vector2f(12.5, 25), _obstacles);
	rightRay = Ray(40, 20, this->position, sf::Vector2f(-12.5, 25), _obstacles);

	// Create perceptron
	leftMotorPerceptron = Perceptron(w1, w2);
}

void Robot::Draw(sf::RenderWindow& window)
{
	window.draw(this->body);
	leftRay.Draw(window);
	rightRay.Draw(window);
}

void Robot::Update(float& deltaTime)
{
	// Update robot position and check for collision
	this->Rotate(currentAngle);
	this->Move(deltaTime);
	
	// Update ray positions
	leftRay.Update(this->position, sf::Vector2f(12.5, 25), currentAngle);
	rightRay.Update(this->position, sf::Vector2f(-12.5, 25), currentAngle);

	// Reset car if out of the field or hot something
	sf::Vector2f circleCenter(400, 400);
	float circleRadius = 400;

	if (obs->CheckForCollision(this->position))
	{
		spawn();
	}

	if ((this->position.x > 800 || this->position.x < 0 || this->position.y < 0 || this->position.y > 800))
	{
		spawn();
	}
}

void Robot::Input(float &deltaTime)
{
	// Perceptron control
	float motorPower = leftMotorPerceptron.Calculate(leftRay.distanceNorm, rightRay.distanceNorm);

	// If power is 0-0.33 it turns left, 0.33 to 0.66 strait, 0.66-1 right.
	if (motorPower < 0.33f)
	{
		currentAngle -= 90 * deltaTime;
	}

	if (motorPower > 0.66f)
	{
		currentAngle += 90 * deltaTime;
	}

	// Manual control
	if (manualControl == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			currentAngle -= 50 * deltaTime;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			currentAngle += 50 * deltaTime;
		}

		if (currentAngle > 360)
		{
			currentAngle -= 360;
		}
		else if (currentAngle < 0)
		{
			currentAngle += 360;
		}
	}
}

void Robot::Move(float &deltaTime)
{
	this->position = this->position + this->forwardVector * this->speed * deltaTime;
	this->body.setPosition(this->position);
}

void Robot::Rotate(float angle)
{
	this->forwardVector = sf::Vector2f(std::cos(deg2rad(angle + 90)), std::sin(deg2rad(angle + 90)));
	this->body.setRotation(currentAngle);
}

void Robot::spawn()
{
	// Spawn different places depending on map mode
	if (obs->mapGenerated == true)
	{
		this->position = sf::Vector2f(400, 100);	
		this->currentAngle = -90;
	}
	else
	{
		this->position = sf::Vector2f(400, 400);
		srand((int)time(0));
		this->currentAngle = rand() % 360;
	}
}