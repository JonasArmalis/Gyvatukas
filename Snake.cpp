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
	this->thickness = 30;
	this->length = 3;
	this->headPos.x = 15;
	this->headPos.y = 10;
	this->head.setFillColor(headColor);
	this->head.setSize(sf::Vector2f(thickness, thickness));

	this->block.setFillColor(bodyColor);
	this->block.setOutlineColor(outlineColor);
	this->block.setSize(sf::Vector2f(thickness, thickness));
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
	this->direction.x = 1;
	this->direction.y = 0;

}

void Snake::move()
{
	Body[int(length - 1)].setPosition(head.getPosition());

	this->Position[int(length - 1)].x = this->headPos.x;
	this->Position[int(length - 1)].y = this->headPos.y;

	this->headPos.x += direction.x;
	this->headPos.y += direction.y;

	head.setPosition(sf::Vector2f(headPos.x * thickness, headPos.y * thickness));

	for (int i = 0; i < length; i++)
	{
		this->Position[i].x = this->Position[int(i + 1)].x;
		this->Position[i].y = this->Position[int(i + 1)].y;
		Body[i].setPosition(sf::Vector2f(Position[i].x * thickness, Position[i].y * thickness));
	}
}

void Snake::eat(Pair foodPos)
{
	this->Position.push_back(foodPos);
	this->length++;
}

void Snake::render(sf::RenderWindow* window)
{
	for (int i = 0; i < length; i++)
	{
		window->draw(Body[i]);
	}
	window->draw(head);
}