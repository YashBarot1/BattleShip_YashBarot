// HumanPlayer.h
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& playerName);
    move getMove() override;
    bool isValidMoveInput(const std::string& input) const;
    move parseMove(const std::string& input) const;
    Board& getBoard();
};

#endif // HUMANPLAYER_H