#include "Game.h"

Game::Game() : m_numberOfPlayers(1), m_levelOfDifficulty(1), m_boardSize(BoardSize::Medium),m_numPairs(52) {
    setupGame();
}

Game::~Game() {}

void Game::setupGame() {
    clearScreen();

    // Size of the board
    int choice = 0;
    while (choice < 1 || choice > 3) {
        std::cout << "Select board size (1 = Small, 2 = Medium, 3 = Large): ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
        }
    }
    // Convert the choice to a BoardSize enum

    m_boardSize = intToBoardSize(choice);
    m_board = std::make_shared <Board>(m_boardSize);
    m_numPairs = static_cast<int>(m_boardSize) / 2;
    clearScreen();
    
    // Number of players
    int numberOfPlayers = -1;
    while (numberOfPlayers != 1 && numberOfPlayers != 2 && numberOfPlayers != 0) {
        std::cout << "How many players will play (1-2)? ";
        std::cin >> numberOfPlayers;
        if(std::cin.fail() || (numberOfPlayers != 1 && numberOfPlayers != 2)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1 or 2.\n";
        }
    }
    m_numberOfPlayers = numberOfPlayers;
    
    clearScreen();

    // Select level of difficulty if there's only one player
    if (m_numberOfPlayers == 1) {
        int levelOfDifficulty = 0;
        while (levelOfDifficulty < 1 || levelOfDifficulty > 3) {        
            std::cout << "Select level of difficulty (1-3, where 1 is easy and 3 is hard): ";
            std::cin >> levelOfDifficulty;  
            if(std::cin.fail() || levelOfDifficulty < 1 || levelOfDifficulty > 3) {
                std::cin.clear(); // Clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
                std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
            }  
        }
        m_levelOfDifficulty = levelOfDifficulty;
    } else {
        // Set a default level of difficulty for multiplayer games
        m_levelOfDifficulty = 1; // Default to easy for multiplayer games
    }

    clearScreen();

    m_players.clear(); // Clear existing players if any
    if (m_numberOfPlayers == 1) {
        m_players.push_back(std::make_unique<HumanPlayer>("Player 1", 0, m_board.get()));
        m_players.push_back(std::make_unique<ComputerPlayer>("Computer", 0, m_board.get(), m_levelOfDifficulty));
    }
    else if (m_numberOfPlayers == 0) {
        m_players.push_back(std::make_unique<ComputerPlayer>("Computer 1", 0, m_board.get(), 3));
        m_players.push_back(std::make_unique<ComputerPlayer>("Computer 2", 0, m_board.get(), 3));
    }
    else {
        std::string name;
        for (int i = 0; i < numberOfPlayers; i++) {
            std::cout << "Enter name for player " << i + 1 << ": ";
            std::cin >> name;
            m_players.push_back(std::make_unique<HumanPlayer>(name, 0, m_board.get()));
        }
    }

    std::string title = "Memory Game\n\n";
    title += "Board size: " + std::to_string(static_cast<int>(m_boardSize)) + "\n";
    title += "Number of players: " + std::to_string(static_cast<int>(m_numberOfPlayers)) + "\n";
    if (m_numberOfPlayers == 1) {
        title += "Level of difficulty: " + std::to_string(static_cast<int>(m_levelOfDifficulty)) + "\n";
    }
    m_board->editTitle(title);

}

void Game::startGame() {
    while (!isGameOver()) {
        clearScreen();
        displayBoard();

        for (auto& player : m_players) 
        {
            while(player->playTurn()){}
            if (isGameOver()) break;
        }
    }

    displayWinner();
}

void Game::displayBoard()
{

    m_board->displayBoard();
}

void Game::displayWinner()
{
    clearScreen();
    
    // ASCII art for the frame
    std::cout << R"(
             ___________
            '._==_==_=_.'
            .-\:      /-.
           | (|:.     |) |
            '-|:.     |-'
              \::.    /
               '::. .'
                 ) (
               _.' '._
              `"""""""`
          )";
    
    // Find the player with the highest score
    Player& winner = *std::max_element(m_players.begin(), m_players.end(), 
        [](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
            return a->getScore() < b->getScore();
        })->get();

    
    // Display the winner with large font
    std::cout << "\n\n";
    std::cout << "      🏆🎉 Congratulations! 🎉🏆\n\n";
    std::cout << "    🥇 The winner is: " << winner.getName() << " 🥇\n\n";
    std::cout << "       With a score of: " << winner.getScore() << " 🎮\n\n\n\n";
    
    // Wait for user confirmation
    std::cout << "Press Enter to continue... ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
}

bool Game::isGameOver() {
    // Determine if the game is over (all cards matched)
    return m_board->isGameOver();
}

