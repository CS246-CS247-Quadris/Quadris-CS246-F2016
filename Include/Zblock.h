#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include <string>
#include "block.h"

using namespace std;
class ZBlock: public Block {
public:
    ZBlock(char type, int number,Board* myboard);               //cstr
    ~ZBlock() {};                                               //dstr
    void Clockwise();                                           //Clockwise
    void CounterClockWise();                                    //CounterClockWise
    string getShape();                                          //getShape
};

#endif