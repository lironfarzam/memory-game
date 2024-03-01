#pragma once

#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "Card.h"
#include "Utility.h"
#include <vector>

class CardFactory {
public:
    static CardFactory& getInstance(); // Static method to get the singleton instance
    std::vector<std::unique_ptr<Card>> createCards(BoardSize boardSize); // Create a vector of unique_ptr to Card objects

private:
    CardFactory(); // Private constructor to prevent instantiation
    CardFactory(const CardFactory&) = delete; // Delete copy constructor
    CardFactory& operator=(const CardFactory&) = delete; // Delete assignment operator
    ~CardFactory(); // Destructor

    std::vector<char> generateSymbols(BoardSize boardSize);

    static CardFactory instance; // The singleton instance
};

#endif // CARD_FACTORY_H
