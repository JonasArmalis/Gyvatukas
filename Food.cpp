#include "Food.h"


Food::Food(int blockLength)
{
	blockSideLength = blockLength;
}

void Food::generatePosition()
{
	//Generates random coordinates.
	position.x = rand() % WIDTH;
	position.y = rand() % HEIGHT;
}




void Food::spawn()
{
	/*
	Spawns food:
	-sets a random possition on grid coords
	-Initializes radius to half block side length
	-sets colors
	*/
	eaten = false;
	generatePosition();
	food.setPosition(position.x * blockSideLength + foodOffset, position.y * blockSideLength + foodOffset);

}
