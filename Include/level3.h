#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include "level.h"
#include <iostream>


class Level3 : public Level {
        public:
         Level3(Board *otherboard, int number_block);                   //cstr
        Block *newBlock();                                              //generate block based on Level
};

#endif
