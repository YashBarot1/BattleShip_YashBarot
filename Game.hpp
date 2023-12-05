// Game.h
#ifndef GAME_H
#define GAME_H

#include "Player.hpp"
#include <memory>

class Game {
private:
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

public:
    void selectPlayers();
    Player* nextPlayer() const;
    bool isRunning() const;
    void play();
    void announceWinner();
};

#endif // GAME_H
