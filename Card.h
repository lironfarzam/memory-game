#pragma once

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

#include "Utility.h"
#include <ostream>

using std::string;
using std::ostream;

class Card {
public:
    // Constructors
    Card();
    Card(char number, string symbol, string colorCode);

    // Member functions
    friend ostream& operator<<(ostream& os, const Card& card);
    void setSeen(bool seen);        // Sets the card as seen
    void setMatched(bool matched);  // Sets the card as matched
    bool isSeen() const;            // Checks if the card has been seen before (for computer players)
    bool isRevealed() const;        // Checks if the card is revealed now
    void flipCard();                // Reveals the card
    bool isMatched() const;         // Checks if the card has been matched
    bool operator== (const Card& card) const; // Checks if two cards are equal


private:
    // Member variables
    char m_number;
    string m_symbol;
    string m_colorCode;
    bool m_seen;
    bool m_revealed;
    bool m_matched;
};

#endif // CARD_H
