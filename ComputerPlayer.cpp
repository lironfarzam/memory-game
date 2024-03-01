#include "ComputerPlayer.h"
#include <iostream>
#include <cstdlib> // for std::rand and std::srand

ComputerPlayer::ComputerPlayer(const std::string &name, int initialScore, Board *board, int levelOfDifficulty):
    Player(name, initialScore, board), m_levelOfDifficulty(levelOfDifficulty)
{
}

bool ComputerPlayer::playTurn()
{
    if (m_board->isGameOver()) {
        return false;
    }

    // Clear the screen and display the board
    clearScreen();
    m_board->displayBoard();
    std::cout << "Computer's turn, score: " << getScore() << std::endl;

    // Wait for a short duration
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Get a list of all flipped cards
    std::vector<std::pair<int, int>> flippedCards = m_board->getSeenCards();

    // Initialize firstPair and secondPair
    std::pair<int, int> firstPair, secondPair;

    // Check the level of difficulty
    if (m_levelOfDifficulty == 3) {
        // Level 3: Check if there are pairs that have already been seen
        bool foundPair = false;

        for (const auto& card1 : flippedCards) {
            for (const auto& card2 : flippedCards) {
                if (card1 != card2 && m_board->isMatch(card1.first, card1.second, card2.first, card2.second)) {
                    firstPair = card1;
                    secondPair = card2;
                    foundPair = true;
                    break;
                }
            }
            if (foundPair) break;
        }

        if (!foundPair) {
            // If no matching pairs found, select random grid coordinates
            firstPair = getRandomGridCoordinates();
            do {
                secondPair = getRandomGridCoordinates();
            } while (secondPair == firstPair || !isValidCardPosition(secondPair));
        }

    }
    else if (m_levelOfDifficulty == 2) {
        // Level 2: Randomly select a flipped card if available, otherwise select a random grid
        if (!flippedCards.empty()) {
            firstPair = flippedCards[std::rand() % flippedCards.size()];

            // Get the column number of the first pair
            int col = firstPair.second;
            // Get all pairs in the same column
            std::vector<std::pair<int, int>> sameColumnPairs;

            for (const auto& card : flippedCards) {
                if (card.second == col) {
                    sameColumnPairs.push_back(card);
                }
            }

            if (!sameColumnPairs.empty()) {
                secondPair = sameColumnPairs[std::rand() % sameColumnPairs.size()];
            }
            else {
                // If no pairs in the same column, select a random grid
                secondPair = getRandomGridCoordinates();
            }
        }
        else {
            // If no flipped cards, select random grid coordinates
            firstPair = getRandomGridCoordinates();
            secondPair = getRandomGridCoordinates();
        }

    }
    else if (m_levelOfDifficulty == 1) {
        // Level 1: Same as level 2, but always select a pair in the same row
        if (!flippedCards.empty()) {
            firstPair = flippedCards[std::rand() % flippedCards.size()];

            // Get the row number of the first pair
            int row = firstPair.first;
            // Get all pairs in the same row
            std::vector<std::pair<int, int>> sameRowPairs;

            for (const auto& card : flippedCards) {
                if (card.first == row) {
                    sameRowPairs.push_back(card);
                }
            }

            if (!sameRowPairs.empty()) {
                secondPair = sameRowPairs[std::rand() % sameRowPairs.size()];
            }
            else {
                // If no pairs in the same row, select random grid coordinates
                secondPair = getRandomGridCoordinates();
            }
        }
        else {
            // If no flipped cards, select random grid coordinates
            firstPair = getRandomGridCoordinates();
            secondPair = getRandomGridCoordinates();
        }
    }

    // Flip the selected cards
    m_board->flipCard(firstPair.first, firstPair.second);
    clearScreen();
    m_board->displayBoard();
    std::cout << "Computer's turn, score: " << getScore() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m_board->flipCard(secondPair.first, secondPair.second);
    clearScreen();
    m_board->displayBoard();
    std::cout << "Computer's turn, score: " << getScore() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Check for a match and update the scores
    if (m_board->isMatch(firstPair.first, firstPair.second, secondPair.first, secondPair.second)) {
        std::cout << "Computer found a match!\n";
        incrementScore(); // Assuming incrementScore increments by 1
        m_board->setMatched(firstPair.first, firstPair.second, secondPair.first, secondPair.second);
        m_board->decriaseNumPairs();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return true;
    }
    else {
        std::cout << "Computer did not find a match.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second, not 2
        // Flip back the cards
        m_board->flipCard(firstPair.first, firstPair.second);
        m_board->flipCard(secondPair.first, secondPair.second);
        return false;
    }
}
