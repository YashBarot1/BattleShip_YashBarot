// Player.cpp
#include "player.hpp"
#include "Game.hpp"

Player::Player(const std::string& playerName) : name(playerName) {}

//getNamr function which returns the name of the player
const std::string& Player::getName() const {
    return name;
}

//getBoard function which returns the board of the plater 
Board& Player::getBoard() {
    return board;
}
