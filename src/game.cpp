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