#pragma once

#include <list>
#include <utility>
#include <SDL.h>

class Snakes
{
public:
	void Init();
	bool Update_snake();
	int get_X_of_head_of_snake();
	int get_Y_of_head_of_snake();
	void enlongSnake();
	bool check_collision();
	bool food_check(std::pair<int, int> food);
	void draw(SDL_Renderer*);
	int getCurrentDirection();
	void setCurrentDirection(int);
private:
	std::list<std::pair<int, int>> snake;
	std::pair<int, int> current_direction;
	std::pair<int, int> last_piece;
};

