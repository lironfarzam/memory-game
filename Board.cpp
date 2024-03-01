#include "Board.h"
#include "CardFactory.h"
#include "Utility.h"
#include <iostream>
#include <random>
#include <algorithm> // Use <algorithm> instead of <__algorithm/shuffle.h>
#include <thread>

Board::Board(BoardSize boardSize) : m_boardSize(boardSize) {
    if (boardSize == BoardSize::Small) {
        m_rows = 2;
        m_cols = 13;
        m_numPairs = 13;
    } else if (boardSize == BoardSize::Medium) {
        m_rows = 4;
        m_cols = 13;
        m_numPairs = 26;
    } else if (boardSize == BoardSize::Large) {
        m_rows = 8;
        m_cols = 13;
        m_numPairs = 52;
    }
    initializeCards();
}

void Board::initializeCards() {
    auto tempCards = CardFactory::getInstance().createCards(m_boardSize);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tempCards.begin(), tempCards.end(), g);

    m_cards.resize(m_rows);
    size_t index = 0;
    for (int row = 0; row < m_rows; ++row) {
        m_cards[row].resize(m_cols); // Resize each row vector to fit the column size
        for (int col = 0; col < m_cols; ++col) {
            m_cards[row][col] = std::move(tempCards[index]);
            ++index;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << "  ";
    for (int col = 0; col < board.m_cols; ++col) {
        os << "   " << static_cast<char>('A' + col) << "   ";
    }
    os << "\n\n";

    for (int row = 0; row < board.m_rows; ++row) {
        os << row + 1 << " ";
        for (int col = 0; col < board.m_cols; ++col) {
            if (board.m_cards[row][col]) {
                os << " " << *(board.m_cards[row][col]) << " ";
            } else {
                os << " [ x ] ";
            }
        }
        os << "\n\n";
    }
    return os;
}


int Board::getRowsSize() const {
    return m_rows;
}

int Board::getColsSize() const {
    return m_cols;
}

void Board::flipCard(int row, int col) {
    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols) {
        m_cards[row][col]->setSeen(true);
        m_cards[row][col]->flipCard(); // Assuming flipCard is the correct method name
    }
}

bool Board::isMatch(int row1, int col1, int row2, int col2) {
    return *(m_cards[row1][col1]) == *(m_cards[row2][col2]);
}


void Board::setMatched(int row1, int col1, int row2, int col2) {
    if (row1 >= 0 && row1 < m_rows && col1 >= 0 && col1 < m_cols &&
        row2 >= 0 && row2 < m_rows && col2 >= 0 && col2 < m_cols) {
        m_cards[row1][col1]->setMatched(true);
        m_cards[row2][col2]->setMatched(true);
    }
}


bool Board::isValidCardPosition(int row, int col) const {
    return row >= 0 && row < m_rows && col >= 0 && col < m_cols &&
        !m_cards[row][col]->isMatched() &&
        !m_cards[row][col]->isRevealed();

}

std::vector<std::pair<int, int>> Board::getSeenCards() const {
    std::vector<std::pair<int, int>> revealedCards;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (m_cards[i][j]->isSeen() && !m_cards[i][j]->isMatched()) {
                revealedCards.push_back(std::make_pair(i, j));
            }
        }
    }
    return revealedCards;
}

void Board::displayBoard() const{
    std::cout << m_title;
    std::cout << m_numPairs << " pairs left\n\n";
    std::cout << *this;
}

bool Board::isGameOver() const
{
    return m_numPairs == 0;
}

void Board::decriaseNumPairs()
{
    m_numPairs--;
}

void Board::editTitle(std::string newTitle)
{
    m_title = newTitle;
}
