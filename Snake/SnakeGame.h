#pragma once
//#include <iostream>
#include "Renderer.h"
//#include <vector>
//#include <list>
#include "Snakes.h"

class SnakeGame
{
public:
	void Init();
	void Update_snake();
	void check_food();
	void draw_snake();
	void draw_food();
	void new_food();
	void draw();
	int getCurrentDirection();
	void setCurrentDirection(int );
	void Quit();
	void clear();
	void delay(int n);

private:
	std::pair<int, int> food_location;
	Renderer newGame;
	Snakes snake;
};

