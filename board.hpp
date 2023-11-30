// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "enemyPiece.hpp"
#include "playerPiece.hpp"
#include "move.hpp"
#include <iostream>

class Board {
private:
    playerPiece playerBoard[400];
    enemyPiece enemyBoard[400];

public:
    Board();
    void reset();
    void makeMove(move move, bool isPlayer);
    bool isLegal(move move) const;
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

#endif // BOARD_H
