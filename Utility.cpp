#include "Utility.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char intToChar(int number) {
    const int MIN_CARD_NUMBER = 1;
    const int MAX_CARD_NUMBER = 13;
    if (number >= MIN_CARD_NUMBER && number <= MAX_CARD_NUMBER) {
        switch (number) {
            case 1: return 'A';
            case 10: return 'T';
            case 11: return 'J';
            case 12: return 'Q';
            case 13: return 'K';
            default: return '0' + number; // Convert number to character
        }
    } else {
        // Handle out-of-range numbers
        throw std::out_of_range("Number out of range for card conversion");
    }
}

std::string chatToSymbol(char chat) {
    switch (chat) {
        case 'H': return "♥";
        case 'D': return "♦";
        case 'C': return "♣";
        case 'L': return "♠";
        default: return " ";
    }
}

std::string chatToColor(char chat) {
    switch (chat) {
        case 'B': return ANSI_COLOR_BLACK; // Black
        case 'R': return ANSI_COLOR_RED; // Red
        default: return ANSI_COLOR_RESET; // Reset color
    }
}

// Function to convert integer to BoardSize enum
BoardSize intToBoardSize(int choice) {
    switch (choice) {
        case 1: return Small;
        case 2: return Medium;
        case 3: return Large;
        default: return Medium;  // Default to Medium if invalid choice
    }
}
