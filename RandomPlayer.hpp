// RandomPlayer.h
#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "ComputerPlayer.hpp"
#include <vector>
#include <random> 

class RandomPlayer : public ComputerPlayer {
public:
    move getMove() override;
    std::vector<int> legalMoves; //storing the legal moves into a vector. 

private: 
    Board board; // Instance of the Board class
    std::mt19937 mt{ std::random_device{}() }; // Mersenne Twister # gen. 

    // is the move legal? 
    bool isLegal(move move);

    // make a legal random move
    void generateLegalMoves();
    std::vector<int> legalMoves; //storing the moves
};




#endif // RANDOMPLAYER_H
