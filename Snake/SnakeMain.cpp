#include "SnakeMain.h"

void SnakeMain::startSnake()
{
	SnakeGame newSnake;
	bool gameLoop = false;
	SDL_Event e;
	newSnake.Init();
	while (!gameLoop) {
		while (SDL_PollEvent(&e) != 0)
		{
			newSnake.draw();
			if (e.type == SDL_QUIT)
			{
				gameLoop = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				//right = 1
				//left = 3
				//downward = 2
				//upward = 4
				if (e.key.keysym.sym == SDLK_DOWN && newSnake.getCurrentDirection() != 4) {
					newSnake.setCurrentDirection(2);
					newSnake.Update_snake();
					newSnake.clear();
					newSnake.draw();
					newSnake.delay(150);
				}
				else if (e.key.keysym.sym == SDLK_RIGHT && newSnake.getCurrentDirection() != 3) {
					newSnake.setCurrentDirection(1);
					newSnake.Update_snake();
					newSnake.clear();
					newSnake.draw();
					newSnake.delay(150);
				}
				else if (e.key.keysym.sym == SDLK_LEFT && newSnake.getCurrentDirection() != 1) {
					newSnake.setCurrentDirection(3);
					newSnake.Update_snake();
					newSnake.clear();
					newSnake.draw();
					newSnake.delay(150);
				}
				else if (e.key.keysym.sym == SDLK_UP && newSnake.getCurrentDirection() != 2) {
					newSnake.setCurrentDirection(4);
					newSnake.Update_snake();
					newSnake.clear();
					newSnake.draw();
					newSnake.delay(150);

				}
			}


		}
		newSnake.Update_snake();
		newSnake.clear();
		newSnake.draw();
		newSnake.delay(150);

	}
	newSnake.Quit();
}