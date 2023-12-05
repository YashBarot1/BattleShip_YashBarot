// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Board.hpp"
#include <string>

class Player {
private:
    std::string name;
    Board board;

public:
    Player(const std::string& playerName);
    const std::string& getName() const;
    virtual move getMove();
    Board& getBoard();
    virtual ~Player() = default;
    bool isValidMove(const move& move) const;
    
};

#endif // PLAYER_H
