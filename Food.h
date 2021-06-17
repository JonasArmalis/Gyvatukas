#pragma once

#include "Pair.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 


class Food
{
private: 

	//Variables
	static int blockSideLength;




public:

	//Constructor
	Food(int blockLength);

	//Public functions
	void spawn();
	void generatePosition();

	//object
	sf::RectangleShape food;

	//Variables
	Pair position;
	bool eaten;
	int offset;

};

