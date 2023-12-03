#include<iostream>
#include "Board.hpp"

int main() {

	//testing if my logic for indexes is valid, it does
	move A{ 1,'s' }; 
	// std::cout << A.getIndex() << std::endl; 

	//testing if random board generation works, it does (ran it 5 times and had 5 diff and valid boards) 
	Board board1; 
	board1.reset(); 
	std::cout << board1 << std::endl; 
}