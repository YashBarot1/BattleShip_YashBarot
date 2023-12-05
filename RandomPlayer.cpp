// RandomPlayer.cpp
#include "RandomPlayer.hpp"

move RandomPlayer::getMove() {
    // Generate legal moves if the vector is empty
    if (legalMoves.empty()) {
        generateLegalMoves();
    }

    // Select a random move from the legal moves
    std::uniform_int_distribution<int> moveDistribution(0, static_cast<int>(legalMoves.size()) - 1);
    int randomIndex = moveDistribution(mt);
    int selectedMove = legalMoves[randomIndex];

    // Convert the selected move to row and column
    move result;
    result.row = selectedMove / 10;
    result.column = static_cast<char>('A' + selectedMove % 10);

    // Remove the selected move from the legal moves
    legalMoves.erase(legalMoves.begin() + randomIndex);

    return result;
}

bool RandomPlayer::isLegal(move move) {
    // Your implementation for checking if the move is legal goes here
    // For example, you can check if the move is within the bounds of the board
    // and if the square has not been hit before
    return board.isLegal(move);
}

void RandomPlayer::generateLegalMoves() {
    // Generate a list of legal moves
    for (int i = 0; i < 100; ++i) {
        if (isLegal(move{ (int)i / 10, static_cast<char>('A' + (int) i % 10) })) {
            legalMoves.push_back(i);
        }
    }
}
