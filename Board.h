#pragma once

#include <vector>
#include <memory> // Include <memory> for std::unique_ptr
#include <iostream>
#include "Utility.h"

// Forward declarations instead of including headers directly
class Card;

class Board {
public:
    Board(BoardSize boardSize); // Constructor to initialize the board with rows and columns
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
    int getRowsSize() const;
    int getColsSize() const;
    bool isValidCardPosition(int row, int col) const;
    void flipCard(int row, int col);
    bool isMatch(int row1, int col1, int row2, int col2);
    void setMatched(int row1, int col1, int row2, int col2);
    std::vector<std::pair<int, int>> getSeenCards() const;
    void displayBoard() const;
    bool isGameOver() const;
    void decriaseNumPairs();
    void editTitle(std::string newTitle);

private:
    std::vector<std::vector<std::unique_ptr<Card>>> m_cards;
    int m_rows;
    int m_cols;
    BoardSize m_boardSize;
    int m_numPairs = 13;
    std::string m_title = "Memory Game\n\n";

    void initializeCards(); // Helper to populate the board with cards
};
