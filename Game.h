#pragma once

#ifndef GAME_H
#define GAME_H

#include <thread> 
#include <iostream>
#include <memory>
#include <vector>


#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Utility.h"


class Game {
public:
    Game();  // Constructor
    ~Game(); // Destructor
    void setupGame();  // Setup game options
    void startGame();  // Start the game loop

private:
    int m_numberOfPlayers = 1;
    int m_levelOfDifficulty = 3;
    BoardSize m_boardSize = BoardSize::Medium;
    std::shared_ptr <Board> m_board = nullptr; // Pointer to a Board object
    std::vector<std::unique_ptr<Player>> m_players = {}; // Vector of Player pointers
    int m_numPairs = 0;

    void displayBoard();
    void displayWinner();
    bool isGameOver();
};

#endif // GAME_H
