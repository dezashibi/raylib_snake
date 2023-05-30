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

#include "raylib.h"

namespace Game
{
	typedef struct
	{
		Color primary;
		Color secondary;
	} Theme;

	void run_snake();
}

namespace Game::Config
{
	namespace
	{
		const Color green = { 173, 204, 96, 255 };
		const Color dark_green = { 43, 51, 24, 255 };
		const Theme retro_theme = { green, dark_green };
		constexpr const char* game_title = "Retro Game";
	}

	const static Theme game_theme = retro_theme;

	constexpr static int cell_size = 30;
	constexpr static int cell_count = 25;

	constexpr static int dimension = cell_size * cell_count;

	void init_game();
}

namespace Game::Utils
{

	Vector2 generate_random_pos();

}