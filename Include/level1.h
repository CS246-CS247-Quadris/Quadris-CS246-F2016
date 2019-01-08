#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "level.h"
#include <iostream>


class Level1 : public Level {
        public:
        Level1(Board *otherboard, int number_block);             //cstr
        Block *newBlock();                                      //generate block based on Level
};

#endif
