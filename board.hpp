// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "enemyPiece.hpp"
#include "playerPiece.hpp"
#include "move.hpp"
#include <iostream>

class Board {
private:
    playerPiece playerBoard[100];
    enemyPiece enemyBoard[100];

public:
    Board();
    void placeShip(int shipSize, playerPiece shipType);
    void reset();
    void makeMove(move move, bool isPlayer);
    bool isLegal(move move) ;
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

#endif // BOARD_H
