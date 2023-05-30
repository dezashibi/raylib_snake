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

void Game::tick(Game::Snake& snake, Game::Food& food)
{
	snake.update();

	// Collision checking
	if (Vector2Equals(snake.body().at(0), food.position()))
	{
		TraceLog(LOG_INFO, "Eating food!");

		food.randomize_pos(snake.body());

		snake.add_segment();
	}

	// Collision with edges
	if (snake.body().at(0).x == Config::cell_count || snake.body().at(0).x == -1) Game::game_over(snake, food);
	if (snake.body().at(0).y == Config::cell_count || snake.body().at(0).y == -1) Game::game_over(snake, food);

	// Collision with itself
	std::deque<Vector2> headless_body = snake.body();
	headless_body.pop_front();
	if (Game::Utils::element_in_deque(snake.body().at(0), headless_body))
	{
		game_over(snake, food);
	}
}

void Game::update(Game::Snake& snake, Game::Food& food)
{
	if (IsKeyPressed(KEY_UP) && snake.direction().y != 1)
	{
		snake.set_direction(0, -1);
		Game::resume_it();
	}

	if (IsKeyPressed(KEY_DOWN) && snake.direction().y != -1)
	{
		snake.set_direction(0, 1);
		Game::resume_it();
	}

	if (IsKeyPressed(KEY_LEFT) && snake.direction().x != 1)
	{
		snake.set_direction(-1, 0);
		Game::resume_it();
	}

	if (IsKeyPressed(KEY_RIGHT) && snake.direction().x != -1)
	{
		snake.set_direction(1, 0);
		Game::resume_it();
	}

	if (IsKeyPressed(KEY_P))
	{
		if (Game::is_running()) Game::pause_it();
		else Game::resume_it();
	}
}

void Game::draw(Game::Snake& snake, Game::Food& food)
{
	food.draw();
	snake.draw();
}

void Game::game_over(Game::Snake& snake, Game::Food& food)
{
	TraceLog(LOG_INFO, "Game Over!");

	snake.reset();

	food.randomize_pos(snake.body());

	Game::pause_it();
}

bool Game::is_running()
{
	return Config::running;
}

void Game::resume_it()
{
	Config::running = true;
}

void Game::pause_it()
{
	Config::running = false;
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

		if (Game::event_triggered(Game::Config::game_interval) && Game::is_running())
		{
			tick(snake, food);
		}

		update(snake, food);

		ClearBackground(Config::game_theme.primary);

		draw(snake, food);

		EndDrawing();
	}

	CloseWindow();
}