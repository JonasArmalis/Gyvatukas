#include "Food.h"

/*
Food::Food(int blockLength, int height, int width)
{
	blockSideLength = blockLength;
	WIDTH = width;
	HEIGHT = height;
	eaten = true;
	offset = 2;

	food.setFillColor(fillColor);
	food.setSize(sf::Vector2f(blockSideLength - 2 * offset, blockSideLength - 2 * offset));
}


void Food::generatePosition(Pair SnakePosition[], int length)
{
	bool isValid = false;

	//Checks weather the generated position is in snake.
	while (!isValid)
	{
		//Generates random coordinates.
		position.x = rand() % WIDTH;
		position.y = rand() % HEIGHT;
		isValid = true;
		for (int i = 0; i < length; i++)
		{
			if (SnakePosition[i].x == position.x &&  SnakePosition[i].y == position.y)
			{
				isValid = false;
			}
		}
	}
}


void Food::spawn(Pair SnakePos[], int length)
{
	
	Spawns food:b
	-sets a random possition on grid coords
	-Initializes radius to half block side length
	-sets colors
	
	eaten = false;
	generatePosition(SnakePos, length);
	food.setPosition(position.x * blockSideLength + offset, position.y * blockSideLength + offset);

}

void Food::render(sf::RenderWindow* window)
{
	window->draw(food);
}*/
