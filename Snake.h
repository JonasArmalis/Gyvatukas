#pragma once


#include "Pair.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 


class Snake
{
private:

	//Objects

	std::vector<sf::RectangleShape> Body;	//Snake's body blocks
	sf::RectangleShape head;				//Snake's head's block.
	sf::RectangleShape block;

	bool dead = false;

	//Colors
	sf::Color bodyColor = sf::Color::Blue; //sf::Color::Color(0, 0, 0);
	sf::Color outlineColor = sf::Color::Color(0, 0, 0);
	sf::Color headColor = sf::Color::Green;//sf::Color::Color(0, 0, 0);


	//Private Functions
	void initVariables();
	void initSnake();

public:

	//Constructors / Destructors
	Snake();
	virtual ~Snake();

	//Variables
	std::vector<Pair> Position;		//The positions of the snake's blocks
	Pair direction;				//Directions expressed as x and y coordinates we add each iteration.
	Pair headPos;				//Position of snake's head (in coordinates)
	int length;				//The legth of the snake (in blocks).
	float thickness;			//The legth of the blocks, which snake is made of. (in pixels)


	//Functions
	void move();
	void eat(Pair foodPos);
	void render(sf::RenderWindow* window);

};
