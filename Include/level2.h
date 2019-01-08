#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "level.h"
#include <iostream>


class Level2 : public Level {
        public:
         Level2(Board *otherboard, int number_block);           //cstr
        Block *newBlock();                                      //generate block based on Level
};

#endif
