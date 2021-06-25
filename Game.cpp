#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->foodOffset = 8;
	this->foodEaten = true;

}

void Game::initWindow()
{
	this->videoMode.height = windowHeight;
	this->videoMode.width = windowWidth;
	this->window = new sf::RenderWindow(this->videoMode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(12);
}


void Game::initFood()
{
	this->food.setFillColor(foodFillColor);
	this->food.setSize(sf::Vector2f(blockSideLength - 2 * foodOffset, blockSideLength - 2 * foodOffset));
}


//Contructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFood();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::generateFoodPos()
{
	bool isValid = false;

	while (!isValid)
	{
		foodPos.x = rand() % WIDTH;
		foodPos.y = rand() % HEIGHT;

		isValid = true;
		for (int i = 0; i < Snaky.length; i++)
		{
			if (CompareCoords(Snaky.Position[i].x, Snaky.Position[i].y, foodPos.x, foodPos.y))
			{
				isValid = false;
			}
		}
	}
}

void Game::spawnFood()
{
	this->generateFoodPos();
	this->food.setPosition(foodPos.x * blockSideLength + foodOffset, foodPos.y * blockSideLength + foodOffset);
	this->foodEaten = false;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else handleKeyInput();
		}
	}
}
void Game::handleKeyInput()
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (Snaky.direction.y == 0)
		{
			Snaky.direction.x = 0;
			Snaky.direction.y = -1;
		}
	}
	else if (ev.key.code == sf::Keyboard::Down)
	{
		if (Snaky.direction.y == 0)
		{
			Snaky.direction.x = 0;
			Snaky.direction.y = 1;
		}
	}
	else if (ev.key.code == sf::Keyboard::Right)
	{
		if (Snaky.direction.x == 0)
		{
			Snaky.direction.x = 1;
			Snaky.direction.y = 0;
		}
	}
	else if (ev.key.code == sf::Keyboard::Left)
	{
		if (Snaky.direction.x == 0)
		{
			Snaky.direction.x = -1;
			Snaky.direction.y = 0;
		}
	}

}
bool Game::CompareCoords(int x1, int y1, int x2, int y2)
{
	return x1 == x2 && y1 == y2;
}
bool Game::SnakeInBounds()
{
	return Snaky.headPos.x <= WIDTH && Snaky.headPos.x >= 0 && Snaky.headPos.y <= HEIGHT && Snaky.headPos.y >= 0;
}
void Game::die()
{
	this->window->close();
}

void Game::updateSnake()
{
	Snaky.move();

	if (CompareCoords(foodPos.x, foodPos.y, Snaky.headPos.x, Snaky.headPos.y))
	{
		Snaky.eat(foodPos);
		foodEaten = true;
	}

	if (!SnakeInBounds())
	{
		this->die();
	}

}
void Game::update()
{
	//Event polling
	this->pollEvents();
	if (this->foodEaten)
		this->spawnFood();
	this->updateSnake();

	//this->terminalOutput();

}
void Game::renderFood()
{
	this->window->draw(food);
}
void Game::render()
{
	/*
		@return void
		Renders game objects
		- Clear old frame
		- Render objects
		- display frame
	*/

	this->window->clear(sf::Color::Black);

	//Draw game objects
	this->renderFood();
	Snaky.render(window);

	this->window->display();
}

//void Game::terminalOutput()
//{
//	system("CLS");
//	std::cout << "Taskai: " cout << "Taskai: " << this->length - 4<< std::endl;
//	
//}