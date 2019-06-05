#include "board.h"
#include <iostream>
#include <vector>

Board::Board(int n) {
    size = n;
    state = new int*[size];
    for(int i = 0; i < size; i++) {
        state[i] = new int[size]{0};
    }
}

int Board::getSize() {
    return size;
}

int** Board::getState() {
    return state;
}

std::vector<int*> Board::getMoves(int* pos) {
    int x = pos[0];
    int y = pos[1];
    int steps[8][2] = {
        {-3,  0},
        {-2, -2},
        {-2,  2},
        { 0, -3},
        { 0,  3},
        { 2, -2},
        { 2,  2},
        { 3,  0}
    };
    std::vector<int*> moves;

    // Check all possible steps
    for(int i = 0; i < 8; i++) {
        int xi = x + steps[i][0];
        int yi = y + steps[i][1];

        // Check if within bounds and empty
        if((0 <= xi && xi < size) && (0 <= yi && yi < size) && (state[yi][xi] == 0)) {
            int* move = new int[2]{xi, yi};
            moves.push_back(move);
        }
    }

    return moves;
}

void Board::setTile(int next, int* move) {
    state[move[1]][move[0]] = next;
}

void Board::display() {
    // Print column indices
    std::cout << '\t';
    for(int i = 0; i < size; i++) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;

    // Print values
    for(int i = 0; i < size; i++) {
        // Print row indices
        std::cout << i << '\t';
        for(int k = 0; k < size; k++) {
            std::cout << state[i][k] << '\t';
        }
        std::cout << std::endl;
    }
}