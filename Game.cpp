// Game.cpp
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include <iostream>

void Game::play() {

	// Play the game
	 do {
		std::cout << player1->getBoard() << std::endl;
		std::cout << player2->getBoard() << std::endl;

		Player* currentPlayer = (rand() % 2 == 0) ? player1.get() : player2.get(); // Randomly select the current player

		std::cout << "It's " << currentPlayer->getName() << "'s turn." << std::endl;
		move move = currentPlayer->getMove();

		Player* opponent = (currentPlayer == player1.get()) ? player2.get() : player1.get();
		opponent->getBoard().makeMove(move, false);
	}while (isRunning());

	// Announce the winner
	announceWinner();
}

bool Game::isRunning() const {
	return !player1->getBoard().isBoardEmpty() && !player2->getBoard().isBoardEmpty();
}

void Game::announceWinner() {
	std::cout << "Game over!" << std::endl;

	if (player1->getBoard().isBoardEmpty() && player2->getBoard().isBoardEmpty()) {
		std::cout << "It's a tie!" << std::endl;
	}
	else if (player1->getBoard().isBoardEmpty()) {
		std::cout << player2->getName() << " is the winner!" << std::endl;
	}
	else {
		std::cout << player1->getName() << " is the winner!" << std::endl;
	}
}

void Game::selectPlayers() {
	// Prompt the user for player types and names
	std::cout << "Enter details for Player 1:\n";
	std::string player1Name;
	std::cout << "Enter player's name: ";
	std::cin >> player1Name;
	player1 = std::make_unique<HumanPlayer>(player1Name); // Assuming Player has a constructor that takes the name
	player1->getBoard().reset();
	player2 = std::make_unique<RandomPlayer>();
	player2->getBoard().reset();

}