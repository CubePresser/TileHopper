#include "board.h"
#include "game.h"

#include <vector>
#include <iostream>

Game::Game(Board* board, int* start) {
    b = board;
    next = 2;
    pos[0] = start[0];
    pos[1] = start[1];
    b->setTile(1, pos);
}

void Game::setPosition(int* newPos) {
    pos[0] = newPos[0];
    pos[1] = newPos[1];
}

int Game::getMove(int n) {
    int move = -1;
    while(std::cin.good()) {
        std::cout << "Which move?: ";
        std::cin >> move;

        // Check if input is valid
        if(std::cin.bad()) {
            throw std::runtime_error("IO Stream corrupted");
        } else if (std::cin.fail()) {
            std::cerr << "== Invalid input: Input must be a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }

        if(0 <= move && move < n) {
            break;
        } else {
            std::cerr << "== Invalid input: Move does not exist." << std::endl;
            continue;
        }
    }
    return move;
}

int Game::getScore() {
    return next;
}

bool Game::turn() {
    b->display();
    std::vector<int*> moves = b->getMoves(pos);

    int numMoves = moves.size();

    for(int i = 0; i < numMoves; i++) {
        std::cout << i << " - { x : " << moves[i][0] << " , y : " << moves[i][1] << " }" << std::endl;
    }

    // End game if no more moves
    if(numMoves <= 0) {
        return false;
    }

    int move = getMove(numMoves);
    pos[0] = moves[move][0];
    pos[1] = moves[move][1];

    b->setTile(next, pos);

    if(next < (b->getSize() * b->getSize())) {
        next += 1;
    }

    return true;
}