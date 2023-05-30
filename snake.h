/***************************************************************************************
    File: values.h
    Author: Navid Dezashibi
    Initial Creation Date: 2023-05-30
    Contact: navid@dezashibi.com
    Website: https://dezashibi.com
    License:
    Please refer to the LICENSE file, repository or website for more information about
    the licensing of this work. If you have any questions or concerns,
    please feel free to contact me at the email address provided above.
 ***************************************************************************************   
    Constant values and configs
 **************************************************************************************/
#pragma once

#include "raylib.h"

namespace Snake
{
	typedef struct
	{
		Color primary;
		Color secondary;
	} Theme;
}

namespace Snake::Config
{
	namespace
	{
		const Color green = { 173, 204, 96, 255 };
		const Color dark_green = { 43, 51, 24, 255 };
		const Theme retro_theme = { green, dark_green };
		constexpr const char* game_title = "Retro Snake";
	}

	const static Theme game_theme = retro_theme;

	constexpr static int cell_size = 30;
	constexpr static int cell_count = 25;

	constexpr static int dimension = cell_size * cell_count;

	static void init_game()
	{
		InitWindow(dimension, dimension, game_title);

		// Settings
		SetTargetFPS(60);
	}
}