#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include<random>
#include<ctime>

#include "Robot.h"
#include "Obstacles.h"
#include <string>

#include<fstream>

class Simulation
{
private:
	sf::RenderWindow window;
    Obstacles obstacles;
    Robot robot;
    void Update();
    void Input();
    void Draw();
public:
    float deltaTime;
	Simulation();
	void Start();
};

Simulation::Simulation() 
{
    // Load settings file
    std::fstream file;
    file.open("settings.txt");
    if (!file.is_open())
    {
        std::cout << "Could not locate settings file" << std::endl;
    }

    // Remove explanation text
    std::string text;
    std::getline(file, text);
    std::getline(file, text);

    // Read obstacle parameters
    file >> text; file >> text;
    bool generateObstacles = false;
    if (text == "yes")
    {
        generateObstacles = true;
    }
    else if (text != "no")
    {
        std::cout << "Something is wrong in settings around 'Obstacles'" << std::endl;
    }

    // Read map parameters
    file >> text; file >> text;
    bool generateMap = false;
    if (text == "yes")
    {
        generateMap = true;
    }
    else if (text != "no")
    {
        std::cout << "Something is wrong in settings around 'map control'" << std::endl;
    }

    // Read manual parameters
    file >> text; file >> text; file >> text;
    bool manualControl = false;
    if (text == "yes")
    {
        manualControl = true;
    }
    else if (text != "no")
    {
        std::cout << "Something is wrong in settings around 'Manual control'" << std::endl;
    }

    // Read speed values
    file >> text; file >> text; file >> text;
    int speed = std::stoi(text);

    // Find weights values
    file >> text; file >> text;
    float w1 = std::stof(text);

    file >> text; file >> text;
    float w2 = std::stof(text);

    // Close file again
    file.close();

    // Create obstacles/map
    obstacles = Obstacles(generateObstacles, generateMap);

    // Create robot with a random start position
    srand((int)time(0));
    float robotStartAngle = rand() % 360;
    robot = Robot(sf::Vector2f(400, 400), robotStartAngle, w1, w2, manualControl, speed, obstacles);

    // Create render window
    window.create(sf::VideoMode(800, 800), "Robot Simulation", sf::Style::Default);
}

void Simulation::Start()
{
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Calculate deltaTime
        sf::Time dt = clock.restart();
        deltaTime = dt.asSeconds();

        // Background
        window.clear(sf::Color::Black);

        // Update game
        Input();
        Update();
        Draw();
        window.display();
    }
}

void Simulation::Draw()
{
    robot.Draw(window);
    obstacles.Draw(window);
}

void Simulation::Update()
{
    robot.Update(deltaTime);
}

void Simulation::Input()
{
    robot.Input(this->deltaTime);
}
