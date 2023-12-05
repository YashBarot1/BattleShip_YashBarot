// ComputerPlayer.h
#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.hpp"

class ComputerPlayer : public Player {
private:
    static int playerCount;
    bool previousMoves[10][10]; // Keeping track of previous moves to avoid repetition

public:
    ComputerPlayer();
    move getMove() override;

private:
    move generateRandomMove() const;
    bool isValidMove(const move& move) const;
};

#endif // COMPUTERPLAYER_H
