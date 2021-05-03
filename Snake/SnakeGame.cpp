#include "SnakeGame.h"

void SnakeGame::Init()
{
	newGame.Init();
	snake.Init();
	new_food();
}

void SnakeGame::Update_snake()
{
	if (!snake.Update_snake()) {
		Quit();
	}
	check_food();
	draw_snake();
	draw_food();

}


void SnakeGame::check_food()
{
	if (food_location.first == snake.get_X_of_head_of_snake() && food_location.second == snake.get_Y_of_head_of_snake())
	{
		snake.enlongSnake();
		new_food();
	}

}

void SnakeGame::new_food()
{
	food_location.first = rand() % 40;
	food_location.second = rand() % 40;
	if (snake.food_check(food_location)) {
		new_food();
	}
}

void SnakeGame::draw_food()
{
	SDL_Rect tmp_rect = { food_location.first * 18  + 8, food_location.second * 18 + 8, 5, 5 };
	SDL_SetRenderDrawColor(newGame.getRenderer(), 0xFF, 0, 0x00, 0xFF); //changing color to red
	SDL_RenderFillRect(newGame.getRenderer(), &tmp_rect); //drawing next piece's outline rectangle
}


void SnakeGame::draw_snake()
{
	snake.draw(newGame.getRenderer());
}

void SnakeGame::draw()
{
	draw_food();
	draw_snake();
	newGame.updateRender();
}

int SnakeGame::getCurrentDirection()
{
	return snake.getCurrentDirection();
}

void SnakeGame::setCurrentDirection(int i)
{
	snake.setCurrentDirection(i);
}

void SnakeGame::Quit() //quit
{
	newGame.quit();
}

void SnakeGame::clear()
{
	newGame.clear();
}

void SnakeGame::delay(int n) //delay
{
	newGame.delay(n);
}