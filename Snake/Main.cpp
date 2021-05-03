#include <SDL.h>
#include <stdio.h>
#include "Renderer.h"
#include "SnakeMain.h"

int main( int argc, char* args[] )
{
	SnakeMain snakeGame;
	snakeGame.startSnake();
	return 0;
}