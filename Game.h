#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

typedef unsigned short int USHORT;

class Game {
public:
    void loop(void);

protected:

private:
    void printLines(void);
    void drawBoard(void);
    bool isReady(void);
    bool firstTurn(void);

    std::string m_player1;
    std::string m_player2;
    std::vector<char> m_openSpaces;
};

#endif // GAME_H
