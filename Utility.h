#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <cstdlib> // For system()
#include <stdexcept>
#include <string>

const std::string ANSI_COLOR_RESET = "\033[0m";
const std::string ANSI_COLOR_BLACK = "\033[30m";
const std::string ANSI_COLOR_RED = "\033[31m";

enum BoardSize { Small = 26, Medium = 52, Large = 104 };

void clearScreen();
char intToChar(int number);
std::string chatToSymbol(char chat);
std::string chatToColor(char chat);
BoardSize intToBoardSize(int choice);
 

#endif // UTILITY_H
