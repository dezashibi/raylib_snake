#include "game.h"
#include "snake.h"
#include "food.h"

using namespace Game;

int main()
{
	Config::init_game();

	auto snake = Snake();
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
		snake.draw();

		EndDrawing();

	}

	CloseWindow();
	return 0;
}
