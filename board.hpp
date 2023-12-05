// Board.h
#ifndef BOARD_H
#define BOARD_H


#include "move.hpp"
#include <iostream>


enum class playerPiece { AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY, WRECK };

enum class enemyPiece { HIT, MISS, EMPTY };


class Board {
private:
    playerPiece playerBoard[100];
    enemyPiece enemyBoard[100];


public:
    Board();
    void placeShip( playerPiece shipType);
    void reset();
    void makeMove(move move, bool isPlayer);
    bool isBoardEmpty();
    bool isLegal(move move) const ;
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

#endif // BOARD_H
