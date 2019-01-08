#include "Include/Lblock.h"
#include <iostream>
#include <vector>
using namespace std;
/* L-BLOCK METHODS */

//LBlock cstr
LBlock::LBlock(char type, int number,Board* myboard) :Block(type,number,myboard){
    cellArray[0] = Cell(3,2,'L',number);
     cellArray[1] = Cell(4,0,'L',number);
     cellArray[2] = Cell(4,1,'L',number);
     cellArray[3] = Cell(4,2,'L',number);
}

//Clockwise
void LBlock::Clockwise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0,c0-2) == 32 &&
            bd->getType(r0- 1,c0-2) == 32){
            cellArray[0].setPosition('r', r0+1);
            cellArray[0].setPosition('c',c0-1);
            cellArray[1].setPosition('r', r0-1);
            cellArray[1].setPosition('c',c0-2);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0-2);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0-2);
            direction = east;
         }
      }else if(direction == east){
         if(c0+ 1 < 11 &&
            bd->getType(r0- 1, c0) == 32 &&
            bd->getType(r0- 1, c0+1) == 32){
            cellArray[0].setPosition('r',r0);
            cellArray[0].setPosition('c',c0-1);
            cellArray[1].setPosition('r', r0-1);
            cellArray[1].setPosition('c',c0+1);
            cellArray[2].setPosition('r', r0-1);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r', r0-1);
            cellArray[3].setPosition('c',c0-1);
            direction = south;
         }
      }else if(direction == south){
         if(r0- 2 >= 0 &&
            bd->getType(r0-2, c0) == 32 &&
            bd->getType(r0-2, c0+1) == 32 &&
            bd->getType(r0, c0+1) == 32){
            cellArray[0].setPosition('r',r0-2);
            cellArray[0].setPosition('c',c0);
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0+1);
            cellArray[3].setPosition('r',r0-2);
            cellArray[3].setPosition('c',c0+1);
            direction = west;
         }
      }else if(direction == west){
         if(c0 + 2 < 11 &&
            bd->getType(r0+1, c0+2) == 32 &&
            bd->getType(r0+2, c0+2) == 32 &&
            bd->getType(r0+2, c0) == 32){
            cellArray[0].setPosition('r', r0+1);
            cellArray[0].setPosition('c',c0+2);
            cellArray[1].setPosition('r',r0+2);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0+2);
            cellArray[2].setPosition('c',c0+1);
            cellArray[3].setPosition('r',r0+2);
            cellArray[3].setPosition('c',c0+2);
            direction = north;
         }
      }
}

//CounterClockWise
void LBlock::CounterClockWise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0- 1 >= 0 &&
            bd->getType(r0, c0 - 1) == 32 &&
            bd->getType(r0 - 1, c0 - 1) == 32 &&
            bd->getType(r0 - 1, c0 - 2) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0-2);
            cellArray[1].setPosition('r',r0+1);
            cellArray[1].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r', r0-1);
            cellArray[3].setPosition('c',c0-1);
            direction = west;
         }
      }else if(direction == east){
         if(c0 + 1 < 11 &&
            bd->getType(r0, c0+1) == 32 &&
            bd->getType(r0-1,c0+1) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0+1);
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0+1);
            direction = north;
         }
      }else if(direction == south){
         if(r0 - 2 >= 0 &&
            bd->getType(r0,c0+1) == 32 &&
            bd->getType(r0-2, c0) == 32){
            int r0 = cellArray[0].getPosition('r');
            int c0 = cellArray[0].getPosition('c');
            cellArray[0].setPosition('r',r0);
            cellArray[0].setPosition('c',c0+1);
            cellArray[1].setPosition('r',r0-2);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0);
            direction = east;
         }
      }else if(direction == west){
         if(c0 + 2 < 11 &&
            bd->getType(r0+1,c0) == 32 &&
            bd->getType(r0+2,c0) == 32 &&
            bd->getType(r0+1,c0+2) == 32){
            cellArray[0].setPosition('r',r0+2);
            cellArray[0].setPosition('c',c0);
            cellArray[1].setPosition('r', r0+1);
            cellArray[1].setPosition('c',c0+2);
            cellArray[2].setPosition('r', r0+1);
            cellArray[2].setPosition('c',c0+1);
            cellArray[3].setPosition('r', r0+1);
            cellArray[3].setPosition('c',c0);
            direction = south;
         }
      }
}

//getShape
string LBlock::getShape(){
    return "  L\nLLL";
}
