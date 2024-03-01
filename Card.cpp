#include "Card.h"

// Default constructor
Card::Card() : m_number(0), m_symbol(" "), m_colorCode(" "), m_seen(false), m_revealed(false), m_matched(false) {}

// Parameterized constructor
Card::Card(char number, string symbol, string colorCode)
    : m_number(number), m_symbol(symbol), m_colorCode(colorCode), m_seen(false), m_revealed(false), m_matched(false) {}


ostream& operator<<(ostream& os, const Card& card) {
    if (card.m_matched) {
        os << card.m_colorCode << "     " << chatToColor('W');
    } else if (!card.m_revealed) {
        os << "[ ? ]";
    } else {
        os << card.m_colorCode << "[" << card.m_number << " " << card.m_symbol << "]" << chatToColor('W');
    }
    return os;
}

// Inside your Card.cpp file
bool Card::operator==(const Card& card) const {
    // Compare each member variable of the two Card objects
    return m_number == card.m_number && m_symbol == card.m_symbol;
}


void Card::setSeen(bool seen) {
    m_seen = seen;
}

void Card::setMatched(bool matched) {
    m_matched = matched;
}

bool Card::isSeen() const {
    return m_seen;
}

bool Card::isMatched() const {
    return m_matched;
}

bool Card::isRevealed() const {
    return m_revealed;
}

void Card::flipCard() {
    m_revealed = !m_revealed;
}
