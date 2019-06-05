#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
    private:
        int size;
        int** state;
    public:
        Board(int size);

        int getSize();
        int** getState();
        std::vector<int*> getMoves(int* pos);

        void setTile(int val, int* move);
        
        void display();
};

#endif