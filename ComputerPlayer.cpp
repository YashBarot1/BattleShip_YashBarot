// ComputerPlayer.cpp
#include "ComputerPlayer.hpp"
#include <cstdlib>
#include <iostream>

int ComputerPlayer::playerCount = 0;

ComputerPlayer::ComputerPlayer() : Player("Computer " + std::to_string(++playerCount)) {
    // Initializing the array to false
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            previousMoves[i][j] = false;
        }
    }
}

move ComputerPlayer::getMove() {
    
    // Generating a random move
    move move = generateRandomMove();

    // Checking if the move has been made before
    while (!isValidMove(move)) {
        move = generateRandomMove();
    }

    // Marking the move as used
    previousMoves[move.row][move.column - 'A'] = true;

    return move;
}

move ComputerPlayer::generateRandomMove() const {
    // Generating a random move
    move move;
    move.row = std::rand() % 10;
    move.column = static_cast<char>('A' + std::rand() % 10);

    return move;
}

bool ComputerPlayer::isValidMove(const move& move) const {
    // Checking if the move is within the bounds of the board
    if (move.row < 0 || move.row >= 10 || move.column < 'A' || move.column > 'J') {
        return false;
    }

    // Checking if the move has already been made
    if (previousMoves[move.row][move.column - 'A']) {
        return false;
    }

    return true;
}
