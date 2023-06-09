/***************************************************************************************
    File: game.h
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
#pragma once

#include <deque>
#include "raylib.h"

namespace Game
{
	class Snake;

	class Food;

	typedef struct
	{
		Color primary;
		Color secondary;
	} Theme;

	namespace /* make them hidden */
	{
		double last_update_time = 0;
		bool running = false;
		int score = 0;

		inline bool event_triggered(double interval)
		{
			auto current_time = GetTime();
			if (current_time - last_update_time >= interval)
			{
				last_update_time = current_time;
				return true;
			}

			return false;
		}
	}

	void tick(Game::Snake& snake, Game::Food& food);

	void update(Game::Snake& snake, Game::Food& food);

	void draw(Game::Snake& snake, Game::Food& food);

	void draw_ui();

	void game_over(Game::Snake& snake, Game::Food& food);

	bool is_running();

	void resume_it();

	void pause_it();

	void run();
}

namespace Game::Config
{
	namespace /* make them hidden */
	{
		const Color green = { 173, 204, 96, 255 };
		const Color dark_green = { 43, 51, 24, 255 };
		const Theme retro_theme = { green, dark_green };

		constexpr int cell_size = 30;
		constexpr int cell_count = 25;
		constexpr int dimension = cell_size * cell_count;

		constexpr const int offset = 75;

		constexpr const char* game_title = "Retro Game";
		constexpr const int game_fps = 60;
		constexpr const double game_interval = 0.2;
		
		Sound score_sound{};
		Sound death_sound{};
	}

	const static Theme game_theme = retro_theme;

	void init_audio();

	void init_game();

	void unload_resources();
}

namespace Game::Utils
{
	bool element_in_deque(const Vector2& element, const std::deque<Vector2>& deque);

	Vector2 generate_random_pos();

	Vector2 generate_random_pos(const std::deque<Vector2>& forbidden_places);
}

namespace Game::Sound
{
	inline void play_score_sound()
	{
		PlaySound(Config::score_sound);
	}

	inline void play_death_sound()
	{
		PlaySound(Config::death_sound);
	}
}