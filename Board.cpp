#include "Board.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() {
	// Initialize the random seed
	std::srand((std::time(0)));
	// Initialize the player's board
	reset();
	// Initialize enemy's board
	
}

void Board::placeShip(int shipSize, playerPiece shipType) {
	if (shipSize > 10) {
		return;
	}
	int start = (std::rand() % 379) + 20; 
	/*
	* This creates a problem, start can be at an index where shipsize is big enough to push part 
	* of the ship in the next row (cant break a ship into two ) 
	*/

	if ((int)(start / 20) != (int)(start + shipSize) / 20) //dealing with the problem above
	{ start -= shipSize;  } 

	for (int i = start; i < start + shipSize; ++i) {
		playerBoard[i] = shipType;
	}

}

void Board::reset() {
	// Erasing all the pieces
	for (int i = 0; i < 400; ++i) {
		playerBoard[i] = playerPiece::EMPTY;
		enemyBoard[i] = enemyPiece::EMPTY; 
	}

	/*
	* Randomly placing
	AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL
	within the player pieces' array
	*/

	placeShip(2, playerPiece::PATROL);
	placeShip(3, playerPiece::CRUISER);
	placeShip(5, playerPiece::AIRCRAFT);
	placeShip(7, playerPiece::SUBMARINE);
	placeShip(10, playerPiece::BATTLESHIP);


}


void Board::makeMove(move move, bool isPlayer) {
	int index = move.getIndex();
	/*here my isPlayer determines if we are examining a move from the player or the enemy,
	*the problem I have is that both playerPiece and enemyPiece are enum classes, restricing me from
	* declarig a bool in them in a logical manner. There's proabably another way to do so
	*/
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
		//here I want to implement the enemy's move but I'm not sure about my approach for it
		//figure it out, had to add "wreck" for a hit in the playerpiece class

		//if its a hit, you have a wreck 
		if (playerBoard[index] != playerPiece::EMPTY) {
			std::cout << "HIT!" << std::endl;
			playerBoard[index] = playerPiece::WRECK;
		}
		// if miss then nothing changes
		else {
			std::cout << "MISS!" << std::endl;
		}
	}
}

bool Board::isLegal(move move) const {
	int index = move.getIndex();

	// Checking if the move is within the bounds of the board
	if (index < 0 || index >= 400) {
		std::cout << "Move is out of bounds." << std::endl;
		return false;
	}

	// Checking if the move has already been done
	if (enemyBoard[index] == enemyPiece::HIT || enemyBoard[index] == enemyPiece::MISS) {
		std::cout << "Move has already been made." << std::endl;
		return false;
	}
	//if neither of the uppercases occur, then it is a valid move
	return true;
}

//overloading << , this one was pretty simple unless of course if I've f'ed it up
std::ostream& operator<<(std::ostream& os, const Board& board) {
	for (int i = 0; i < 400; ++i) {
		/*
		* os << static_cast<char>(static_cast<int>('A') + (i % 20)) << (i / 20) << ": ";
		* this line prints indexes against the cell, here for testing purposes
		*/
		switch (board.playerBoard[i]) {
		case playerPiece::AIRCRAFT:
			os << 'A';
			break;
		case playerPiece::BATTLESHIP:
			os << 'B';
			break;
		case playerPiece::CRUISER:
			os << 'C';
			break;
		case playerPiece::PATROL:
			os << 'P';
			break; 
		case playerPiece::SUBMARINE:
				os << 'S';
				break;	
		default :
			os << ' '; //empty if the spot is empty
		}

		if (i % 20 == 0 && i != 0) { os << "  +   ";  }

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

		if (i % 20 == 0 && i != 0 ) { os  << std::endl; } //new line for next row
	}

	return os;
}
