#include "Snakes.h"


void Snakes::Init()
{
	current_direction.first = 1;
	current_direction.second = 0;
	for (int i = 0; i < 5; i++) 
	{
		std::pair<int, int> temp_location;
		temp_location.first = 20 - i;
		temp_location.second = 20;
		snake.push_back(temp_location);
	}

}

bool Snakes::Update_snake()
{
	if (check_collision())
	{
		return 0;
	}

	last_piece = snake.back();
	for (auto iter = snake.rbegin(); iter != snake.rend(); iter++) 
	{
		if (*iter != snake.front()) {
			auto tmp_iter = std::next(iter, 1);
			(*iter).first = (*tmp_iter).first;
			(*iter).second = (*tmp_iter).second;
		}
		else if (*iter == snake.front())
		{
			(*iter).first += current_direction.first;
			(*iter).second += current_direction.second;
		}
	}
	return 1;
}

int Snakes::get_X_of_head_of_snake()
{
	return snake.front().first;
}


int Snakes::get_Y_of_head_of_snake()
{
	return snake.front().second;
}

void Snakes::enlongSnake()
{
	snake.push_back(last_piece);
}


bool Snakes::check_collision()
{
	std::pair<int, int> tmp = snake.front();
	tmp.first += current_direction.first;
	tmp.second += current_direction.second;

	if (tmp.first > 40 || tmp.first < 0 || tmp.second < 0 || tmp.second > 40)
	{
		return 1;
	}
	else
	{
		for (auto iter = snake.begin(); iter != snake.end(); ++iter)
		{
			if ((*iter).first == tmp.first && (*iter).second == tmp.second) {
				return 1;
			}
		}

	}

	return 0;
}


bool Snakes::food_check( std::pair<int, int> food)
{
	for (auto iter = snake.begin(); iter != snake.end(); ++iter)
	{
		if ((*iter).first == food.first && (*iter).second == food.second) {
			return 1;
		}
	}
	return 0;
}

void Snakes::draw(SDL_Renderer* renderer)
{
	for (auto iter = snake.begin(); iter != snake.end(); ++iter)
	{
		SDL_Rect tmp_rect = { (*iter).first * 18 + 3 , (*iter).second * 18 + 3 , 15, 15 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &tmp_rect);
	}
}

int Snakes::getCurrentDirection()
{
	if (current_direction.first == 1)
		return 1; // right
	else if (current_direction.first == -1)
		return 3; // left
	else if (current_direction.second == 1)
		return 2; //downward
	else if (current_direction.second == -1)
		return 4; //upward
}

void Snakes::setCurrentDirection(int i)
{
	if (i == 1)
	{
		current_direction.first = 1;
		current_direction.second = 0;
	}

	else if (i == 3)
	{
		current_direction.first = -1;
		current_direction.second = 0;
	}
	else if (i == 2)
	{
		current_direction.first = 0;
		current_direction.second = 1;
	}
	else if (i == 4)
	{
		current_direction.first = 0;
		current_direction.second = -1;
	}
}