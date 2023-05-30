#include "game.h"

int main()
{
	Game::Config::init_game();

	Game::run();

	Game::Config::unload_resources();
	return 0;
}
