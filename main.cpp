#include "Game.h"

#include <iostream>

auto main(int argc, char *argv[]) -> int {
    Game *game = new Game();
    game->loop();

    return 0;
}
