#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include <string>
#include "block.h"
using namespace std;

class TBlock: public Block {
public:
    TBlock(char type, int number,Board* myboard);           //cstr
    ~TBlock() {};                                           //dstr
    void Clockwise();                                       //Clockwise
    void CounterClockWise();                                //CounterClockWise
    string getShape();                                      //getShape
};

#endif