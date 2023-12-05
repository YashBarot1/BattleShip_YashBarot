// Player.cpp
#include "player.hpp"
#include "Game.hpp"

Player::Player(const std::string& playerName) : name(playerName) {}

//getNamr function which returns the name of the player
const std::string& Player::getName() const {
    return name;
}

move Player::getMove() {
    move a; 
    return a; 
}

//getBoard function which returns the board of the plater 
Board& Player::getBoard() {
    return board;
}

bool Player::isValidMove(const move& move) const {
    // Check if the move is within the bounds of the board
    if (move.row < 0 || move.row >= 10 || move.column < 'A' || move.column > 'J') {
        return false;
    }

    // Check if the move has already been made
    if (!board.isLegal(move)) {
        return false;
    }

    return true;
}
