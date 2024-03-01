# Memory Game Project

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Game Architecture](#game-architecture)
  - [Class Structure](#class-structure)
  - [ComputerPlayer's Difficulty Strategy](#computerplayers-difficulty-strategy)
- [Building the Project with CMake](#building-the-project-with-cmake)
- [Coding Best Practices](#coding-best-practices)
- [Tip on Player Modes](#tip-on-player-modes)


https://github.com/lironfarzam/memory-game/assets/87701576/c9ca8631-169c-4145-ba79-f5c23e2da3d2


## Introduction
The Memory Game is a console-based C++ application that tests and improves memory skills through the classic card-matching game. Featuring multiple difficulty levels and dynamic board sizes, the game offers a challenging experience for all players, from beginners to advanced.

To enhance the "Features" section with gameplay and basic instructions, consider the following addition:

---

## Features
- **Adaptive Difficulty Levels:** The computer opponent adjusts its difficulty to provide a suitable challenge for players of all skill levels.
- **Multiple Modes of Play:** Engage in a single-player mode to challenge the computer or compete in a two-player mode for head-to-head gameplay.
- **Configurable Board Sizes:** Choose from Small, Medium, or Large board sizes to customize the gameplay complexity and duration.
- **Elegant Console Interface:** Enjoy a visually engaging gaming experience with an elegant console interface that utilizes ANSI color codes.

### Gameplay and Basic Instructions
The Memory Game is a classic card-matching game designed to test and improve your memory. Players take turns flipping two cards at a time, with the goal of finding matching pairs. Matches are removed from the board, and the player with the most matches at the end of the game wins.

**How to Play:**
1. **Start the Game:** After launching the game, select your game mode (Single-player or Two-player) and choose the board size (Small, Medium, Large).
2. **Taking Turns:** 
   - In Single-player mode, you will take turns against the computer. In Two-player mode, players take turns flipping cards.
   - On each turn, select two cards to flip. If the cards match, they are removed from the board, and you get another turn.
   - If the cards do not match, they are flipped back over, and it's the next player's turn.
3. **Winning the Game:** The game ends when all pairs have been matched. The player with the most matches wins the game.

**Tips for Success:**
- Pay close attention to the symbols on each card as they are revealed.
- Try to remember the positions of cards for better chances of matching them on your turn.
- Use the adaptive difficulty settings to gradually increase the challenge as you improve.

By following these instructions and tips, you'll be well on your way to becoming a Memory Game master. Enjoy testing your memory and challenging your friends or the computer in this engaging game!

## Getting Started

### Prerequisites
- C++17 compliant compiler
- CMake 3.14 or higher for building the project

### Installation
1. **Clone the repository:**
   ```sh
   git clone https://github.com/lironfarzam/memory-game.git
   ```
2. **Navigate to the project directory:**
   ```sh
   cd memory-game
   ```
3. **Build the project:**
   - Create a build directory and navigate into it:
     ```sh
     mkdir build && cd build
     ```
   - Generate the makefile and build the project:
     ```sh
     cmake .. && make
     ```
4. **Run the game:**
   ```sh
   ./MemoryGame
   ```

## Game Architecture

### Class Structure
- **Game:** Manages game flow, including setup and player turns.
- **Board:** Handles the game board, tracking card states and matches.
- **Card:** Represents individual game cards.
- **Player:** Abstract base class for players, with derived classes for human and computer players.
- **HumanPlayer:** Manages interactions for human players.
- **ComputerPlayer:** Simulates an opponent with varying strategies.
- **Utility:** Provides utility functions for the game interface.

### ComputerPlayer's Difficulty Strategy
The ComputerPlayer's strategy varies with difficulty levels, from random card selection to strategic recall of previously seen cards, offering engaging gameplay across all levels.

## Building the Project with CMake
- **Compile the project:** Instructions for using CMake to build the project, as detailed in the [Building the Project with CMake](#building-the-project-with-cmake) section.
- **Running the executable:** How to run the compiled game from the terminal.

## Coding Best Practices
In developing the Memory Game, we've meticulously adhered to modern C++ best practices, including consistent coding styles, effective memory management through the use of smart pointers, and a modular design to ensure maintainability. Central to our architectural approach is the implementation of design patterns such as Singleton and Factory, exemplified by the `CardFactory` class. This class acts as a singular point for dynamic card generation, adjusting complexity with board size and ensuring gameplay adaptability. Through these practices, we not only foster a robust and scalable game architecture but also demonstrate our unwavering commitment to coding excellence and architectural integrity.


### Tip on Player Modes:

The Memory Game is designed to accommodate a range of gameplay preferences, offering three distinct modes for players:

- **Single-Player Mode:** Select '1 player' to dive into a solo challenge against the computer, making it ideal for practicing your memory skills.
- **Two-Player Mode:** Choose '2 players' for a competitive head-to-head experience with a friend, where you take turns trying to match pairs.
- **Auto-Play Mode:** Opt for '0 players' to let the computer take on itself in a demonstration of the game's AI capabilities. This mode is perfect for observing the game's mechanics or enjoying it as a spectator.

This enhanced explanation of the game modes ensures clarity, catering to conventional expectations while introducing an innovative auto-play feature that showcases the game's artificial intelligence.
