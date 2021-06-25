#include "Snake.h"
#include <iostream>

Snake::Snake()
{
	initVariables();
	initSnake();
}

Snake::~Snake()
{
}

void Snake::initVariables()
{
	thickness = 30;
	length = 3;
	headPos.x = 15;
	headPos.y = 10;
	head.setFillColor(headColor);
	head.setSize(sf::Vector2f(thickness, thickness));

	block.setFillColor(bodyColor);
	block.setOutlineColor(outlineColor);
	block.setOutlineThickness(1);
	head.setOutlineThickness(1);
	head.setOutlineColor(outlineColor);

	block.setSize(sf::Vector2f(thickness, thickness));
}

void Snake::initSnake()
{
	/*
		@return void
		-Initializes the snake of "length" on start.
		-Initializes stariting direction to rigth.
	*/
	for (int i = 0; i < length; i++)
	{
		Position.push_back(headPos);
		Body.push_back(block);
		Body[i].setPosition(headPos.x * thickness, headPos.y * thickness);
		headPos.x++;
	}


	//setting direction to right
	direction.x = 1;
	direction.y = 0;

}

void Snake::move()
{
	Body[int(length - 1)].setPosition(head.getPosition());

	Position[int(length - 1)].x = headPos.x;
	Position[int(length - 1)].y = headPos.y;

	headPos.x += direction.x;
	headPos.y += direction.y;

	head.setPosition(sf::Vector2f(headPos.x * thickness, headPos.y * thickness));

	for (int i = 0; i < length; i++)
	{
		Position[i].x = Position[int(i + 1)].x;
		Position[i].y = Position[int(i + 1)].y;
		Body[i].setPosition(sf::Vector2f(Position[i].x * thickness, Position[i].y * thickness));
	}
}

void Snake::eat(Pair foodPos)
{
	block.setPosition(sf::Vector2f(foodPos.x, foodPos.y));
	Body.push_back(block);
	length++;
	Position.push_back(foodPos);
}

void Snake::render(sf::RenderWindow* window)
{
	for (int i = 0; i < length; i++)
	{
		window->draw(Body[i]);
	}
	window->draw(head);
}