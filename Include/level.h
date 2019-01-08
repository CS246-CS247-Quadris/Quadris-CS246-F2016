#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <iostream>
using namespace std;
class Block;
class Board;

class Level {
    protected:
    Board *myboard;                                                                                              
    int block_number;                   
        public:
        Level(Board *otherboard, int number_block);                             //cstr
        virtual Block *newBlock() = 0;                                          //generate block based on Level
};

#endif
