#include "Include/Iblock.h"
//#include "Include/block.h"
#include <iostream>
#include <vector>
using namespace std;
/* I-BLOCK METHODS */

//Iblock cstr
IBlock::IBlock(char type, int number, Board* myboard):Block(type,number,myboard){
    cellArray[0] = Cell(3,0,'I',number);
    cellArray[1] = Cell(3,1,'I',number);
    cellArray[2] = Cell(3,2,'I',number);
    cellArray[3] = Cell(3,3,'I',number);
}

//Clockwise
void IBlock::Clockwise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == east){
         if(r0 - 3 >= 0 &&
            bd->getType(r0, c0) == 32 &&
            bd->getType(r0 - 1, c0) == 32 &&
            bd->getType(r0 - 2, c0) == 32 &&
            bd->getType(r0 - 3, c0) == 32){
            cellArray[0].setPosition('r', r0-3);
            cellArray[0].setPosition('c', c0);
            cellArray[1].setPosition('r', r0-2);
            cellArray[1].setPosition('c', c0);
            cellArray[2].setPosition('r', r0-1);
            cellArray[2].setPosition('c', c0);
            cellArray[3].setPosition('r', r0);
            cellArray[3].setPosition('c', c0);
            direction = north;
         }
      }else {
         if(c0 + 3 < 11 &&
            bd->getType(r0, c0) == 32 &&
            bd->getType(r0, c0+1) == 32 &&
            bd->getType(r0, c0+2) == 32 &&
            bd->getType(r0, c0+3) == 32){
            cellArray[0].setPosition('r', r0+3);
            cellArray[0].setPosition('c', c0);
            cellArray[1].setPosition('r', r0+3);
            cellArray[1].setPosition('c', c0+1);
            cellArray[2].setPosition('r', r0+3);
            cellArray[2].setPosition('c', c0+2);
            cellArray[3].setPosition('r', r0+3);
            cellArray[3].setPosition('c', c0+3);
            direction = east;
         }
      }
}


//CounterClockWise
void IBlock::CounterClockWise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == east){
         if(r0 - 3 >= 0 &&
            bd->getType(r0,c0) == 32 &&
            bd->getType(r0 - 1, c0) == 32 &&
            bd->getType(r0 - 2, c0) == 32 &&
            bd->getType(r0 - 3, c0) == 32){
            cellArray[0].setPosition('r', r0);
            cellArray[0].setPosition('c', c0);
            cellArray[1].setPosition('r', r0-1);
            cellArray[1].setPosition('c', c0);
            cellArray[2].setPosition('r', r0-2);
            cellArray[2].setPosition('c', c0);
            cellArray[3].setPosition('r', r0-3);
            cellArray[3].setPosition('c', c0);
            direction = north;
         }
      }else {
         if(c0 + 3 < 11 &&
            bd->getType(r0, c0) == 32 &&
            bd->getType(r0, c0+1) == 32 &&
            bd->getType(r0, c0+2) == 32 &&
            bd->getType(r0, c0+3) == 32){
            cellArray[0].setPosition('r', r0+3);
            cellArray[0].setPosition('c', c0);
            cellArray[1].setPosition('r', r0+3);
            cellArray[1].setPosition('c', c0+1);
            cellArray[2].setPosition('r', r0+3);
            cellArray[2].setPosition('c', c0+2);
            cellArray[3].setPosition('r', r0+3);
            cellArray[3].setPosition('c', c0+3);
            direction = east;
         }
      }
}

//getShape
string IBlock::getShape(){
    return "IIII";
}
