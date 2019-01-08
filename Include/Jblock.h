#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include <string>
#include "block.h"
using namespace std;
class JBlock: public Block {
public:
    JBlock(char type, int number,Board* myboard);                   //cstr
    ~JBlock() {};                                                   //dstr
    void Clockwise();                                               //Clockwise
    void CounterClockWise();                                        //CounterClockWise
    string getShape();                                              //getShape
};

#endif