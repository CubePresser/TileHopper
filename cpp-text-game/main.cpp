#include <stdio.h>
#include <string>
#include <iostream>
#include "board.h"

#include <vector>

#define LINE printf("\n")

int main(int argc, char** argv) {
    int size = 0;

    while(std::cin.good()) {
        std::cout << "Board size: ";
        std::cin >> size;

        // Check if input is valid
        if(std::cin.bad()) {
            throw std::runtime_error("IO Stream corrupted");
        } else if (std::cin.fail()) {
            std::cerr << "== Invalid input: Input must be a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }

        if(size <= 0) {
            std::cerr << "== Invalid input: Size must be greater than 0." << std::endl;
            continue;
        } else {
            break;
        }
    } LINE;

    Board b = Board(size);

    std::vector<int*>moves = b.getMoves(4, 4);

    for(int i = 0; i < moves.size(); i++) {
        std::cout << i << " - { x : " << moves[i][0] << " , y : " << moves[i][1] << " }" << std::endl;
    }
    // TODO: Start game
}