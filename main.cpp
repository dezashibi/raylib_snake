#include <iostream>
#include "snake.h"
#include "food.h"

using namespace Snake;

int main()
{
	Config::init_game();

	auto food = Food();

	/*
	 * Game Loop
	 * 1. Event handling
	 * 2. Update positions
	 * 3. Drawing objects
	 * */

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(Config::game_theme.primary);

		food.draw();

		EndDrawing();

	}

	CloseWindow();
	return 0;
}
