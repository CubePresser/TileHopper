#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "board.h"
#include "game.h"

bool testSTDIN() {
    // Check if input is valid
    if(std::cin.bad()) {
        throw std::runtime_error("IO Stream corrupted");
    } else if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        return false;
    } else {
        return true;
    }
}

int promptInt(const char* prompt) {
    int result;
    while(std::cin.good()) {
        std::cout << prompt;
        std::cin >> result;

        if(!testSTDIN()) {
            std::cerr << "== Invalid input: Input must be a number." << std::endl;
            continue;
        }

        break;
    }

    return result;
}

bool inBounds(int val, int low, int high) {
    return (low <= val && val <= high);
}

int main(int argc, char** argv) {
    int size = 0;

    while((size = promptInt("Board size: ")) <= 0) {
        std::cerr << "== Invalid input: Size must be greater than 0." << std::endl;
    }

    Board b = Board(size);

    int x, y;

    while(
        !inBounds(x = promptInt("Start x: "), 0, size - 1) || 
        !inBounds(y = promptInt("Start y: "), 0, size - 1)
    ) {
        std::cerr << "== Invalid input: Start position does not exist." << std::endl;
    }

    int start[2] = {x, y};

    Game g = Game(&b, start);

    while(g.turn());

    int score = g.getScore();

    if(score == size * size) {
        std::cout << "You win! Congrats!" << std::endl;
    } else {
        std::cout << "You lost. Final score: " << score-1 << std::endl;
    }
}