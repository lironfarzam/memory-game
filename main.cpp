// main.cpp
#include "Game.h"
#include <iostream>
#include <string>

int main() {
    bool playAgain = true;
    
    while (playAgain) {

        Game game;
        game.startGame();
        
        // Ask the player if they want to play again
        std::string response;
        std::cout << "Do you want to play again? (yes/no): ";
        std::cin >> response;
        // to lower case
        for (char& c : response) {
            c = tolower(c);
        }
        if (response != "yes") {
            playAgain = false;
        }
    }
    
    return 0;
}