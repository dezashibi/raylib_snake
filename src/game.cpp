/***************************************************************************************
    File: game.cpp
    Author: Navid Dezashibi
    Initial Creation Date: 2023-05-30
    Contact: navid@dezashibi.com
    Website: https://dezashibi.com
    License:
    Please refer to the LICENSE file, repository or website for more information about
    the licensing of this work. If you have any questions or concerns,
    please feel free to contact me at the email address provided above.
 ***************************************************************************************   
    << OTHER DESCRIPTIONS >>
 **************************************************************************************/
#include "game.h"

#include "snake.h"
#include "food.h"

using namespace Game;

void Config::init_game()
{
	InitWindow(dimension, dimension, game_title);

	// Settings
	SetTargetFPS(60);
}

Vector2 Utils::generate_random_pos()
{
	float x = GetRandomValue(0, Config::cell_count - 1);
	float y = GetRandomValue(0, Config::cell_count - 1);
	return Vector2{ x, y };
}

bool RunTime::event_triggered(double interval)
{
	auto current_time = GetTime();
	if (current_time - last_update_time >= interval)
	{
		last_update_time = current_time;
		return true;
	}

	return false;
}

void RunTime::update(Game::Snake& snake, Game::Food& food)
{
	if (RunTime::event_triggered(0.2)) snake.update();

	if (IsKeyPressed(KEY_UP) && snake.direction().y != 1) snake.set_direction(0, -1);
	if (IsKeyPressed(KEY_DOWN) && snake.direction().y != -1) snake.set_direction(0, 1);
	if (IsKeyPressed(KEY_LEFT) && snake.direction().x != 1) snake.set_direction(-1, 0);
	if (IsKeyPressed(KEY_RIGHT) && snake.direction().x != -1) snake.set_direction(1, 0);
}

void RunTime::draw(Game::Snake& snake, Game::Food& food)
{
	food.draw();
	snake.draw();
}

void Game::run()
{
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

		RunTime::update(snake, food);

		ClearBackground(Config::game_theme.primary);

		RunTime::draw(snake, food);

		EndDrawing();
	}

	CloseWindow();
}