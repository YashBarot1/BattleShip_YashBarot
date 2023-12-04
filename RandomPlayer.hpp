// RandomPlayer.h
#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "ComputerPlayer.hpp"

class RandomPlayer : public ComputerPlayer {
public:
    move getMove() override;
};

#endif // RANDOMPLAYER_H
