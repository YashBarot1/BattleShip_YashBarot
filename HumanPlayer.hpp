// HumanPlayer.h
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& playerName);
    move getMove() override;
};

#endif // HUMANPLAYER_H
