// ComputerPlayer.h
#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.hpp"

class ComputerPlayer : public Player {
private:
    static int playerCount;

public:
    ComputerPlayer();
};

#endif // COMPUTERPLAYER_H
