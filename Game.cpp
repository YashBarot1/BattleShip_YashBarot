// Game.cpp
#include "Game.hpp"
#include "RandomPlayer.hpp"
#include "HumanPlayer.hpp"
#include <iostream>

void Game::selectPlayers() {
    char player1Type, player2Type;

        std::string playerName;
        std::cout << "Enter player 1's name: ";
        std::cin >> playerName;
        player1 = std::make_unique<HumanPlayer>(playerName);
        player2 = std::make_unique<RandomPlayer>();
  
    
}

Player* Game::nextPlayer() const {
    static bool player1Turn = true;
    return player1Turn ? player1.get() : player2.get();
}

bool Game::isRunning() const {
     return !player1->getBoard().isBoardEmpty() && !player2->getBoard().isBoardEmpty();
}

void Game::play() {
    do {
        std::cout << player1->getName() << std::endl;
        std::cout << player2->getName() << std::endl;

        Player* currentPlayer = nextPlayer();
        std::cout << "It's " << currentPlayer->getName() << "'s turn." << std::endl;

        move move = currentPlayer->getMove();
        if (currentPlayer == player1.get()) {
            player2->getBoard().makeMove(move, false);
        }
        else {
            player1->getBoard().makeMove(move, false);
        }
    } while (isRunning()); 
}

void Game::announceWinner() {
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
