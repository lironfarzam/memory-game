#pragma once

// HumanPlayer.h
#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& name, int initialScore = 0, Board* board = nullptr);
    bool playTurn() override;
    std::pair<int, int> getPlayerCardInput(const std::string& message);

};

#endif // HUMAN_PLAYER_H