#pragma once

#include "Snake.h"
#include "Pair.h"

#include <vector>
#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


/*
	Game class
*/

class Game
{
private:
	//Variables

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;


	//Game logic
	static const int windowHeight = 900;
	static const int windowWidth = 1500;
	static const int blockSideLength = 30;
	static const int WIDTH = windowWidth / blockSideLength;
	static const int HEIGHT = windowHeight / blockSideLength;

	int foodOffset;
	bool foodEaten;
	bool gameOver;


	//Game objects
	Snake Snaky;

	//Coloring

	sf::Color backgroundColor = sf::Color::Color(0, 0, 0);
	sf::Color gridColor = sf::Color::Color(22, 41, 166);//backgroundColor;  
	sf::Color foodFillColor = sf::Color::Color(176, 6, 39);
	sf::Color foodOutlineColor = foodFillColor; // sf::Color::Color(0, 255, 0);

	//sf::Color deadColor = sf::Color::Color(100, 100, 100);


	//sf::RectangleShape blocks[WIDTH][HEIGHT];
	sf::RectangleShape food;
	//std::vector<intPair> snake;

	Pair foodPos;

	//Private functions
	void initVariables();
	void initWindow();
	void initFood();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions

	bool CompareCoords(int x1, int y1, int x2, int y2);
	bool SnakeInBounds();
	void generateFoodPos();
	void spawnFood();
	void pollEvents();
	void handleKeyInput();
	void die();

	void updateSnake();
	void update();

	void renderFood();
	void render();

	void terminalOutput();
};
