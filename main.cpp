#include<iostream>
#include "Board.hpp"

int main() {

	//testing if my logic for indexes is valid, it does
<<<<<<< Updated upstream
	move A{ 1,'s' }; 
	std::cout << A.getIndex() << std::endl; 
=======
	move A{ 1,'B' }; 
	move B{ 2,'B' };
	move C{ 2,'B' };
	move D{ 4,'B' };
	move E{ 5,'B' };
	// std::cout << A.getIndex() << std::endl; 
>>>>>>> Stashed changes

	//testing if random board generation works, it does (ran it 5 times and had 5 diff and valid boards) 
	Board board1;  
	std::cout << board1 << std::endl; 
	board1.makeMove(A, false);
	board1.makeMove(B, false);
	board1.makeMove(C, false);
	board1.makeMove(D, false);
	board1.makeMove(E, false);

	std::cout << board1 << std::endl;

}