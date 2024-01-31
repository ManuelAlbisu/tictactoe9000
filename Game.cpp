#include "Game.h"

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

bool Game::isReady() {
    std::cout << "Enter player 1's name: ";
    std::cin >> m_player1;

    std::cout << "Enter player 2's name: ";
    std::cin >> m_player2;

    char choice;
    std::cout << "\nStart game? [y/N]: ";
    std::cin >> choice;

    if(tolower(choice) == 'y') {
        std::cout << "\nHope you enjoy the game " << m_player1 << " and " << m_player2 << ", good luck!\n\n";
        return true;
    } else {
        std::cout << "See you next time!\n";
        return false;
    }
}

bool Game::firstTurn() {
    // 0 for crosses, 1 for knots
    const USHORT offset = 1;
    const USHORT range = 2;
    bool first;

    srand((unsigned)time(NULL));
    USHORT random = offset + (rand() % range);

    std::cout << m_player1 << " (Crosses)" << " vs. " << m_player2 << " (Knots).\n";

    if(random - 1) {
        first = true;
        std::cout << m_player1 << " goes first."  << std::endl;
    } else {
        first = false;
        std::cout << m_player2 << " goes first."  << std::endl;
    }

    return first;
}

void Game::loop() {
    bool choice = isReady();

    for(USHORT i = 0; i < 9; ++i)
        m_openSpaces.push_back(i);

    if(choice) {
        bool current = firstTurn();
        drawBoard();
    }

    // while(m_occupiedSpaces.size() != 9) { }
}
