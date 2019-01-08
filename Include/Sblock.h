#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include <string>
#include "block.h"
using namespace std;

class SBlock: public Block {
public:
    SBlock(char type, int number,Board* myboard);               //cstr
    ~SBlock() {};                                               //dstr
    void Clockwise();                                           //Clockwise
    void CounterClockWise();                                    //CounterClockWise
    string getShape();                                          //getShape
};  

#endif