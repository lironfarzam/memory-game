#include "Player.h"
#include "Board.h"
#include <iostream>

Player::Player(const std::string& name, int initialScore, Board* board)
    : m_name(name), m_score(initialScore), m_board(board) {}

Player::~Player() {}

const std::string& Player::getName() const {
    return m_name;
}

void Player::setName(const std::string& name) {
    m_name = name;
}

int Player::getScore() const {
    return m_score;
}

void Player::setScore(int score) {
    m_score = score;
}

void Player::incrementScore(int amount) {
    m_score += amount;
}

void Player::decrementScore(int amount) {
    m_score -= amount;
}

void Player::printPlayerInfo() const {
    std::cout << "Player Name: " << m_name << std::endl;
    std::cout << "Player Score: " << m_score << std::endl;
}

std::pair<int, int> Player::getRandomGridCoordinates() const {
    // Generate random row and column numbers within the board size
    int row = rand() % m_board->getRowsSize();
    int col = rand() % m_board->getColsSize();
    return std::make_pair(row, col);
}

bool Player::isValidCardPosition(const std::pair<int, int>& cardPosition) const {
    int row = cardPosition.first;
    int col = cardPosition.second;

    return row >= 0 && row < m_board->getRowsSize() &&
            col >= 0 && col < m_board->getColsSize() &&
            m_board->isValidCardPosition(row, col);
}
