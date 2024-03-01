#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(const std::string &name, int initialScore, Board *board):
    Player(name, initialScore, board)
{
}

bool HumanPlayer::playTurn()
{
    if (m_board->isGameOver()) {
        return false;
    }

    std::pair<int, int> firstCard, secondCard;
    int bonus = 0;
    int score = 10;

    firstCard = getPlayerCardInput("Select the first card (e.g., A1): ");
    auto begin = std::chrono::steady_clock::now();
    
    m_board->flipCard(firstCard.first, firstCard.second);
    clearScreen();
    m_board->displayBoard();

    secondCard = getPlayerCardInput("Select the second card (e.g., A2): ");
    auto end = std::chrono::steady_clock::now();

    m_board->flipCard(secondCard.first, secondCard.second);
    clearScreen();
    m_board->displayBoard();

    auto timeTaken = std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
    bonus = std::max(0, 30 - static_cast<int>(timeTaken));

    if (m_board->isMatch(firstCard.first, firstCard.second, secondCard.first, secondCard.second)) {
        std::cout << "Match found! Bonus: " << bonus << " points\n";
        incrementScore(score + bonus);
        m_board->setMatched(firstCard.first, firstCard.second, secondCard.first, secondCard.second);
        return true;
    } else {
        std::cout << "No match found. Try again.\n";
        m_board->flipCard(firstCard.first, firstCard.second);
        m_board->flipCard(secondCard.first, secondCard.second);
    }

    std::cout << "Press enter to continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n').get();
    return false;
}

std::pair<int, int> HumanPlayer::getPlayerCardInput(const std::string& message) {
    std::pair<int, int> cardPosition;
    char col;
    int row;
    bool validInput = false;

    while (!validInput) {
        std::cout << message;
        std::cin >> col >> row;

        // Convert column to uppercase
        col = std::toupper(col);

        // Convert row number to zero-based index
        row--;

        // Check if the input is valid
        if (std::cin.fail() || col < 'A' || col >= 'A' + m_board->getColsSize() || row < 0 || row >= m_board->getRowsSize()) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a valid card position.\n";
            continue; // Prompt again for input
        }
        // if the cord is isValidCardPosition
        else if (!m_board->isValidCardPosition(row, col - 'A')) {
            std::cout << "Card has already been matched. Please select another card.\n";
        }
        else {
            validInput = true;
        }
    }

    cardPosition.first = row;
    cardPosition.second = col - 'A';

    return cardPosition;
}

