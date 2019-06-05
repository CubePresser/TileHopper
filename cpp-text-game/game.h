#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
    private:
        int pos[2];
        int next;

        Board* b;

        void setPosition(int* pos);
        int getMove(int choices);
    public:
        Game(Board* b, int* start);
        bool turn();
        int getScore();
};

#endif