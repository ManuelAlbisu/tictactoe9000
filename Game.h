#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
public:
    void loop(void);

protected:

private:
    void printLines(void);
    void drawBoard(void);
    bool isPlayerReady(void);
    bool firstTurn(void);

    std::vector<char> m_openSpaces;
};

#endif // GAME_H
