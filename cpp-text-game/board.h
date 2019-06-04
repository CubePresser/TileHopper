#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
    private:
        int size;
        int** state;
    public:
        Board(int);
        int getSize();

        std::vector<int*> getMoves(int, int);
        void display();
};

#endif