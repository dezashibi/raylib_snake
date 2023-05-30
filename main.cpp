#include "game.h"

using namespace Game;

int main()
{
	Config::init_game();

	run_snake();
	return 0;
}
