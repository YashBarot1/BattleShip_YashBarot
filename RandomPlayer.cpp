#include "RandomPlayer.hpp"
#include <iostream>

move RandomPlayer::getMove() {
    generateLegalMoves(); // Generate legal moves
    if (legalMoves.empty()) {
        std::cerr << "No legal moves available." << std::endl;
        return move{ -1, 'Z' }; // Return an invalid move if no legal moves
    }

    // Choose a random move from the legal moves
    std::uniform_int_distribution<int> dist(0, static_cast<int>(legalMoves.size()) - 1);
    int randomIndex = dist(mt);
    return move{ legalMoves[randomIndex] / 10, static_cast<char>('A' + (legalMoves[randomIndex] % 10)) };
}

bool RandomPlayer::isLegal(move move) {
    int index = move.getIndex();

    // Checking if the move is within the bounds of the board
    if (index < 0 || index >= 100) {
        return false;
    }

    // Checking if the move has already been done
    if (board.enemyBoard[index] == enemyPiece::HIT || board.enemyPiece[index] == enemyPiece::MISS) {
        return false;
    }

    return true;
}

void RandomPlayer::generateLegalMoves() {
    legalMoves.clear(); // Clear the existing legal moves

    for (int i = 0; i < 100; ++i) {
        if (isLegal(move{ i / 10, static_cast<char>('A' + (i % 10)) })) {
            legalMoves.push_back(i); // Add legal moves to the vector
        }
    }
}