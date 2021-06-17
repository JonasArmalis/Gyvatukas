#include "Game.h"

//Private functions
void Game::initVariables()
{
	window = nullptr;

	//Game logic
	foodOffset = 5;
	foodEaten = true;

}

void Game::initWindow()
{
	videoMode.height = windowHeight;
	videoMode.width = windowWidth;
	window = new sf::RenderWindow(videoMode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(7);
}


void Game::initFood()
{
	food.setFillColor(foodFillColor);
	food.setSize(sf::Vector2f(blockSideLength - 2 * foodOffset, blockSideLength - 2 * foodOffset));
}


//Contructors / Destructors
Game::Game()
{
	initVariables();
	initWindow();
	initFood();
}

Game::~Game()
{
	delete window;
}

//Accessors
const bool Game::running() const
{
	return window->isOpen();
}

//Functions
void Game::generateFoodPos()
{
	bool isValid = false;

	//Generates random coordinates.
	foodPos.x = rand() % WIDTH;
	foodPos.y = rand() % HEIGHT;

	//Checks weather the generated position is in snake.
	while (!isValid)
	{
		isValid = true;
		for (int i = 0; i < Snaky.length; i++)
		{
			if (CompareCoords(Snaky.Position[0].x, Snaky.Position[0].y, foodPos.x, foodPos.y))
			{
				isValid = false;
			}
		}
	}

}

void Game::spawnFood()
{
	/*
		Spawns food:
		-sets a random possition on grid coords
		-Initializes radius to half block side length
		-sets colors
	*/
	foodEaten = false;
	generateFoodPos();
	food.setPosition((foodPos.x * blockSideLength) + foodOffset, (foodPos.y * blockSideLength) + foodOffset);
	
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
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
	window->close();
}

void Game::updateSnake()
{
	Snaky.move();

	if (CompareCoords(foodPos.x, foodPos.y, Snaky.headPos.x, Snaky.headPos.y))
	{
		Snaky.eat(foodPos);
		foodEaten = true;
	}
	
	if (!SnakeInBounds() )
	{
		die();
	}
		
}

void Game::update()
{
	//Event polling
	pollEvents();
	if(foodEaten)
		spawnFood();
	updateSnake();

	//terminalOutput();
	
}

void Game::renderFood()
{
	window->draw(food);
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

	window->clear(sf::Color::Black);

	//Draw game objects
	renderFood();
	Snaky.render(window);

	window->display();
}

//void Game::terminalOutput()
//{
//	system("CLS");
//	std::cout << "Taskai: " cout << "Taskai: " << length - 4<< std::endl;
//	
//}
