#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include <string>
#include "block.h"
using namespace std;

class LBlock: public Block {
public:
   LBlock(char type, int number,Board* myboard);                //cstr
    ~LBlock() {};                                               //dstr
    void Clockwise();                                           //Clockwise
    void CounterClockWise();                                    //CounterClockWise
     string getShape();                                         //getShape
};

#endif