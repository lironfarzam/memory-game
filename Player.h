#pragma once

// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <thread> // Include for std::this_thread::sleep_for

#include "Card.h"
#include "Board.h" // Include Board.h instead of forward declaration

class Player {
public:
    Player(const std::string& name, int initialScore = 0, Board* board = nullptr);
    virtual ~Player();

    const std::string& getName() const;
    void setName(const std::string& name);
    int getScore() const;
    void setScore(int score);
    std::pair<int, int> getRandomGridCoordinates() const;
    virtual bool isValidCardPosition(const std::pair<int, int>& cardPosition) const; // Make it virtual
    void incrementScore(int amount = 10);
    void decrementScore(int amount = 10);
    virtual bool playTurn() = 0; // Make it pure virtual
    void printPlayerInfo() const;
    

protected:
    std::string m_name;
    int m_score;
    Board* m_board;
};

#endif // PLAYER_H
