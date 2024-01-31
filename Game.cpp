#include "Game.h"

#include <iostream>

typedef unsigned short int USHORT;

const USHORT COLUMNS  = 3;
const USHORT ROWS = 3;
const char P1SIGN = 'X';
const char P2SIGN = 'O';

void Game::printLines() {
    std::cout << "   ";

    for(USHORT i = 0; i < COLUMNS; ++i)
        std::cout << " ---";

    std::cout << std::endl;
}

void Game::drawBoard() {
    // simplify, check for m_openSpaces[i] % 3 = 0 to split line
    printLines();

    for(USHORT i = 0; i < ROWS; ++i) {
        std::cout << "  ";

        for(USHORT j = 0; j < COLUMNS; ++j)
            std::cout << " |  ";

        std::cout << " | " << std::endl;

        printLines();
    }
}

bool Game::isPlayerReady() {
    char choice;
    std::cout << "Ready to begin? [y/N]: ";
    std::cin >> choice;

    if(tolower(choice) == 'y') {
        std::cout << "Good luck!\n\n";
        return true;
    } else {
        std::cout << "See you next time!\n";
        return false;
    }
}

bool Game::firstTurn() {
    // 0 for crosses, 1 for knots
    USHORT offset = 1;
    USHORT range = 2;

    srand((unsigned)time(NULL)); // provides a seed value
    USHORT random = offset + (rand() % range); // generates random number {1, 2}

    std::cout << "Player " << random << " goes first."  << std::endl;

    return random - 1;
}

void Game::loop() {
    bool choice = isPlayerReady();

    for(USHORT i = 0; i < 9; ++i)
        m_openSpaces.push_back(i);

    if(choice) {
        bool current = firstTurn();
        drawBoard();
    }

    // while(m_occupiedSpaces.size() != 9) { }
}
