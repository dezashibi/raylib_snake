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

#include <algorithm>

#include "snake.h"
#include "food.h"

void Game::Config::init_game()
{
	InitWindow(dimension, dimension, game_title);

	// Settings
	SetTargetFPS(game_fps);
}

bool Game::Utils::element_in_deque(const Vector2& element, const std::deque<Vector2>& deque)
{
	return std::any_of(deque.begin(), deque.end(), [&](const Vector2& el)
	{
		return Vector2Equals(el, element);
	});
}

Vector2 Game::Utils::generate_random_pos()
{
	float x = GetRandomValue(0, Config::cell_count - 1);
	float y = GetRandomValue(0, Config::cell_count - 1);
	return Vector2{ x, y };
}

Vector2 Game::Utils::generate_random_pos(const std::deque<Vector2>& forbidden_places)
{
	Vector2 position = generate_random_pos();

	while (element_in_deque(position, forbidden_places))
	{
		position = generate_random_pos();
	}

	return position;
}

void Game::tick(double interval, Game::Snake& snake, Game::Food& food)
{
	if (Game::event_triggered(interval))
	{
		snake.update();

		// Collision checking
		if (Vector2Equals(snake.body()[0], food.position()))
		{
			TraceLog(LOG_INFO, "Eating food!");

			food.randomize_pos(snake.body());
		}
	}
}

void Game::update(Game::Snake& snake, Game::Food& food)
{
	if (IsKeyPressed(KEY_UP) && snake.direction().y != 1) snake.set_direction(0, -1);
	if (IsKeyPressed(KEY_DOWN) && snake.direction().y != -1) snake.set_direction(0, 1);
	if (IsKeyPressed(KEY_LEFT) && snake.direction().x != 1) snake.set_direction(-1, 0);
	if (IsKeyPressed(KEY_RIGHT) && snake.direction().x != -1) snake.set_direction(1, 0);
}

void Game::draw(Game::Snake& snake, Game::Food& food)
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

		tick(Game::Config::game_interval, snake, food);

		update(snake, food);

		ClearBackground(Config::game_theme.primary);

		draw(snake, food);

		EndDrawing();
	}

	CloseWindow();
}