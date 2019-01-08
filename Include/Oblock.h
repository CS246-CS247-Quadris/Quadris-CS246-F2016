#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include <string>
#include "block.h"
using namespace std;

class OBlock: public Block {
public:
    OBlock(char type, int number,Board* myboard);           //cstr
    ~OBlock() {};                                           //dstr
    void Clockwise();                                       //Clockwise
    void CounterClockWise();                                //CounterClockWise
    string getShape();                                      //getShape
};

#endif