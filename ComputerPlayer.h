#pragma once

// ComputerPlayer.h
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const std::string& name, int initialScore, Board* board, int levelOfDifficulty);
    bool playTurn() override;

private:
int m_levelOfDifficulty;
};

#endif // COMPUTER_PLAYER_H