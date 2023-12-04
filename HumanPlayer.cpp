// HumanPlayer.cpp
#include "HumanPlayer.hpp"
#include <iostream>


HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

move HumanPlayer::getMove() {
    std::string input;
    move move;

    do {
        std::cout << getName() << ", enter your move (e.g., 2B): ";
        std::getline(std::cin, input);
    } while (!isValidMoveInput(input));

    move = parseMove(input);

    return move;
}

bool HumanPlayer::isValidMoveInput(const std::string& input) const {
    // Check if the input has two characters
    if (input.size() != 2) {
        std::cout << "Invalid input. Please enter a valid move (e.g., 2B)." << std::endl;
        return false;
    }

    // Check if the first character is a digit representing the row
    if (!std::isdigit(input[0])) {
        std::cout << "Invalid input. The first character should be a digit representing the row." << std::endl;
        return false;
    }

    // Check if the second character is an uppercase letter representing the column
    if (!std::isupper(input[1])) {
        std::cout << "Invalid input. The second character should be an uppercase letter representing the column." << std::endl;
        return false;
    }

    // Check if the row is within the valid range (1-10)
    int row = input[0] - '0';
    if (row < 1 || row > 10) {
        std::cout << "Invalid input. The row should be between 1 and 10." << std::endl;
        return false;
    }

    // Check if the column is within the valid range (A-J)
    char column = input[1];
    if (column < 'A' || column > 'J') {
        std::cout << "Invalid input. The column should be between A and J." << std::endl;
        return false;
    }

    // Check if the selected square has already been hit
    move move = parseMove(input);
    if (false) {
        std::cout << "Invalid move. This square has already been hit." << std::endl;
        return false;
    }

    return true;
}



move HumanPlayer::parseMove(const std::string& input) const {
    // Parse the input string into a Move object
    int row = input[0] - '0' - 1;  // Adjust to 0-based index
    char column = std::toupper(input[1]);

    return move{ row, column };
}
