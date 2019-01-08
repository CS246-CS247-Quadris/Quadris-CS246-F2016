#include "Include/Sblock.h"
#include <iostream>
#include <vector>
using namespace std;
/* S-BLOCK METHODS */
//SBlock cstr
SBlock::SBlock(char type, int number,Board* myboard) :Block(type,number,myboard){
    cellArray[0] = Cell(3,1,'S',number);
     cellArray[1] = Cell(3,2,'S',number);
     cellArray[2] = Cell(4,0,'S',number);
     cellArray[3] = Cell(4,1,'S',number);
}
//Clockwise
void SBlock::Clockwise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0, c0-1) == 32 &&
            bd->getType(r0 - 1,c0-1) == 32){
            cellArray[1].setPosition('r',r0+1);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0-1);
            direction = east;
         }
      }else {
         if(c0 + 1 < 11 &&
            bd->getType(r0,c0+1) == 32 &&
            bd->getType(r0+1,c0-1) == 32){
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0+1);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0);
            direction = north;
         }
      }
}

//CounterClockWise
void SBlock::CounterClockWise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0, c0-1) == 32 &&
            bd->getType(r0 - 1, c0-1) == 32){
            cellArray[1].setPosition('r',r0+1);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0-1);
            direction = east;
         }
      }else {
         if(c0 + 1 < 11 &&
            bd->getType(r0, c0+1) == 32 &&
            bd->getType(r0 +1, c0-1) == 32){
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0+1);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0);
            direction = north;
         }
      }
}

//getShape
string SBlock::getShape(){
    return " SS\nSS";
}
