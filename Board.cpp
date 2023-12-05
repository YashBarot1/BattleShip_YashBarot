#include "Board.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() {
	// Initialize the random seed
	std::srand((std::time(0)));

	// Initialize the player and enemy's board
	reset();
	
	
}

void Board::placeShip( playerPiece shipType) {
	
	int start = (std::rand() % 88) + 10;
	
	
		playerBoard[start] = shipType;
	

}

void Board::reset() {
	// Erasing all the pieces
	for (int i = 0; i < 100; ++i) {
		playerBoard[i] = playerPiece::EMPTY;
		enemyBoard[i] = enemyPiece::EMPTY;
	}

	/*
	* Randomly placing
	AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL
	within the player pieces' array
	*/

	placeShip( playerPiece::PATROL);
	placeShip( playerPiece::CRUISER);
	placeShip( playerPiece::AIRCRAFT);
	placeShip( playerPiece::SUBMARINE);
	placeShip( playerPiece::BATTLESHIP);

}


void Board::makeMove(move move, bool isPlayer) {
	int index = move.getIndex();
	// here my isPlayer determines if we are examining a move from the player or the enemy
	if (isPlayer) {

		//  If the square is not empty, it as HIT, otherwise it as MISS

		if (enemyBoard[index] != enemyPiece::EMPTY) {
			std::cout << "HIT!" << std::endl;
			enemyBoard[index] = enemyPiece::HIT;
		}
		else {
			std::cout << "MISS!" << std::endl;
			enemyBoard[index] = enemyPiece::MISS;
		}
	}
	else {
		//when the enemy makes a move, if a square wasn't empty, it is now wrecked (literally)
		if (playerBoard[index] != playerPiece::EMPTY) {
			std::cout << "HIT!" << std::endl;
			playerBoard[index] = playerPiece::WRECK;
		}
		else {
			std::cout << "MISS!" << std::endl;
			
		}
	}
}

bool Board::isBoardEmpty() {
	int i = 0; 
	int numberofhits=0;
		while(i<100) {
			if (enemyBoard[i] == enemyPiece::HIT) {
				
				++numberofhits;
		}
			if (numberofhits == 5) {
				return false; 
			}
		if (playerBoard[i] != playerPiece::EMPTY || playerBoard[i] == playerPiece::WRECK) {
			return false;
		}
		++i; 
	}
	return true;
}
bool Board::isLegal(move move)  const {
	int index = move.getIndex();

	// Checking if the move is within the bounds of the board
	if (index < 0 || index >= 100) {
		std::cout << "Move is out of bounds." << std::endl;
		return false;
	}

	// Checking if the move has already been done
	if (enemyBoard[index] == enemyPiece::HIT || enemyBoard[index] == enemyPiece::MISS) {
		std::cout << "Move has already been made." << std::endl;
		return false;
	}
	//if neither of the upper cases occur, then it is a valid move
	return true;
}

//overloading << , this one was pretty simple unless of course if I've f'ed it up
std::ostream& operator<<(std::ostream& os, const Board& board) {
	for (int i = 1; i <= 100; ++i) {
		/*
		* os << static_cast<char>(static_cast<int>('A') + (i % 10)) << (i / 10) << ": ";
		* this line prints indexes against the cell, here for testing purposes
		*/
		switch (board.playerBoard[i]) {
		case playerPiece::AIRCRAFT:
			os << "A";
			break;
		case playerPiece::BATTLESHIP:
			os << "B";
			break;
		case playerPiece::CRUISER:
			os << "C";
			break;
		case playerPiece::PATROL:
			os << 'P';
			break;
		case playerPiece::SUBMARINE:
			os << 'S';
			break;
		default:
			os << '#'; //empty if the spot is empty
		}

		if (i % 10 == 0 && i != 0) {
			os << "    ";
			for (int j = (int)i % 10; j <= 10; ++j)
			{
				switch (board.enemyBoard[i]) {
				case enemyPiece::HIT:
					os << 'H';
					break;
				case enemyPiece::MISS:
					os << 'M';
					break;
				case enemyPiece::EMPTY:
					os << 'E';
					break;
				default:
					os << ' ';
				}
			}
			os << '\n'; //new line for next row
		}
	}
	return os;
}
