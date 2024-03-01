#include "CardFactory.h"
#include "Utility.h"
#include <iostream>
#include <thread>

CardFactory::CardFactory() {}

CardFactory::~CardFactory() {}

CardFactory& CardFactory::getInstance() {
    return instance;
}

std::vector<char> CardFactory::generateSymbols(BoardSize boardSize) {
    std::vector<char> symbols;

    switch (boardSize) {
        case Small:
            symbols = {'L'}; // Leaf symbol for small board
            break;
        case Medium:
            symbols = {'L', 'H'}; // Leaf and heart symbols for medium board
            break;
        case Large:
            symbols = {'L', 'H', 'D', 'C'}; // Leaf, heart, diamond, and club symbols for large board
            break;
        default:
            // Handle unrecognized board size
            std::cerr << "Unrecognized board size\n";
            break;
    }
    return symbols;
}

std::vector<std::unique_ptr<Card>> CardFactory::createCards(BoardSize boardSize) {
    std::vector<char> symbols = generateSymbols(boardSize);
    std::vector<std::unique_ptr<Card>> cards;

    const int MAX_CARD_NUMBER = 13;
    for (char symbol : symbols) {
        std::string color = (symbol == 'H' || symbol == 'D') ? chatToColor('R') : chatToColor('B');
        for (int number = 1; number <= MAX_CARD_NUMBER; ++number) {

            // Use std::make_shared to create a new Card and add it to the vector
            cards.push_back(std::make_unique <Card>(intToChar(number), chatToSymbol(symbol), color));
        }
    }
    
    // Double the cards - you'll need to duplicate each unique_ptr, which requires explicit cloning if Card has clone() method
    size_t originalSize = cards.size();
    for (size_t i = 0; i < originalSize; ++i) {
        // Assuming Card has a clone function; otherwise, you'll need to manually copy each one.
        cards.push_back(std::make_unique<Card>(*cards[i]));
    }
    
    // //print out the cards
    // for (const auto& card : cards) {
    //     std::cout << *card << std::endl;
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }

    return cards;
}


CardFactory CardFactory::instance; // Initialize the singleton instance
