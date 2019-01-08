#include "Include/Zblock.h"
#include <iostream>
#include <vector>
using namespace std;
/* Z-BLOCK METHODS */

//Zblock cstr
ZBlock::ZBlock(char type, int number,Board* myboard) :Block(type,number,myboard){
    cellArray[0] = Cell(3,0,'Z',number);
     cellArray[1] = Cell(3,1,'Z',number);
     cellArray[2] = Cell(4,1,'Z',number);
     cellArray[3] = Cell(4,2,'Z',number);
}
//Clockwise
void ZBlock::Clockwise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0+ 1, c0) == 32 &&
            bd->getType(r0- 1, c0+1) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0);
            direction = east;
         }
      }else {
         if(c0 + 1 < 11 &&
            bd->getType(r0+2, c0) == 32 &&
            bd->getType(r0+1, c0+1) == 32){
            cellArray[0].setPosition('r',r0+1);
            cellArray[0].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0+2);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+2);
            cellArray[3].setPosition('c',c0+1);
            direction = north;
         }
      }
}

//CounterClockWise
void ZBlock::CounterClockWise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0+ 1, c0) == 32 &&
            bd->getType(r0- 1, c0+1) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0);
            direction = east;
         }
      }else {
         if(c0 + 1 < 11 &&
            bd->getType(r0+2, c0) == 32 &&
            bd->getType(r0+1, c0+1) == 32){
            cellArray[0].setPosition('r',r0+1);
            cellArray[0].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0+2);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+2);
            cellArray[3].setPosition('c',c0+1);
            direction = north;
         }
      }
}

//getShape
string ZBlock::getShape(){
    return "ZZ\n ZZ";
}
