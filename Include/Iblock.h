#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include <string>
#include "block.h" 
using namespace std;
//#include "board.h"
//class Board;
//class Block;


class IBlock : public Block {
public:
    IBlock(char type, int number,Board* myboard);           //cstr
    ~IBlock() {};                                           //dstr
    void Clockwise();                                       //Clockwise
    void CounterClockWise();                                //CounterClockWise
    string getShape();                                      //getShape
};



#endif