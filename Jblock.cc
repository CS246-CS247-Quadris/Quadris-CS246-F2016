#include "Include/Jblock.h"
#include <iostream>
#include <vector>
using namespace std;
/* JBLOCK METHODS */

//Jblock cstr
JBlock::JBlock(char type, int number,Board* myboard):Block(type,number,myboard){
     cellArray[0] = Cell(3,0,'J',number);
     cellArray[1] = Cell(4,0,'J',number);
     cellArray[2] = Cell(4,1,'J',number);
     cellArray[3] = Cell(4,2,'J',number);
}

//Clockwise
void JBlock::Clockwise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0 - 1, c0) == 32 &&
            bd->getType(r0 - 1, c0 + 1) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0+1);
            cellArray[1].setPosition('r',r0-1);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0);
            direction = east;
         }
      }else if(direction == east){
         if(c0 + 1 < 11 &&
            bd->getType(r0 + 1, c0) == 32 &&
            bd->getType(r0 + 1, c0+1) == 32 &&
            bd->getType(r0 + 2, c0+1) == 32){
            cellArray[0].setPosition('r',r0+2);
            cellArray[0].setPosition('c',c0+1);
            cellArray[1].setPosition('r',r0+1);
            cellArray[1].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0+1);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+1);
            cellArray[3].setPosition('c',c0-1);
            direction = south;
         }
      }else if(direction == south){
         if(r0 - 2 >= 0 &&
            bd->getType(r0, c0-2) == 32 &&
            bd->getType(r0, c0-1) == 32 &&
            bd->getType(r0-2,c0-1) == 32){
            cellArray[0].setPosition('r',r0);
            cellArray[0].setPosition('c',c0-2);
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0-1);
            cellArray[3].setPosition('r',r0-2);
            cellArray[3].setPosition('c',c0-1);
            direction = west;
         }
      }else if(direction == west){
         if(c0 + 2 < 11 &&
            bd->getType(r0-1, c0) == 32 &&
            bd->getType(r0, c0+2) == 32){
            cellArray[0].setPosition('r',r0-1);
            cellArray[0].setPosition('c',c0);
            cellArray[1].setPosition('r',r0);
            cellArray[1].setPosition('c',c0);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0+1);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0+2);
            direction = north;
         }
      }
}

//CounterClockWise
void JBlock::CounterClockWise(){
    int r0 = cellArray[0].getPosition('r');
    int c0 = cellArray[0].getPosition('c');
    if(direction == north){
         if(r0 - 1 >= 0 &&
            bd->getType(r0- 1,c0+1) == 32 &&
            bd->getType(r0,c0+1) == 32){
            cellArray[0].setPosition('r',r0+1);
            cellArray[0].setPosition('c',c0);
            cellArray[1].setPosition('r',r0+1);
            cellArray[1].setPosition('c',c0+1);
            cellArray[2].setPosition('r',r0);
            cellArray[2].setPosition('c',c0+1);
            cellArray[3].setPosition('r',r0-1);
            cellArray[3].setPosition('c',c0+1);
            direction = west;
         }
      }else if(direction == east){
         if(c0 + 1 < 11 &&
            bd->getType(r0 + 2, c0) == 32 &&
            bd->getType(r0 + 2, c0 + 1) == 32){
            cellArray[0].setPosition('r',r0+1);
            cellArray[0].setPosition('c',c0-1);
            cellArray[1].setPosition('r',r0+2);
            cellArray[1].setPosition('c',c0-1);
            cellArray[2].setPosition('r',r0+2);
            cellArray[2].setPosition('c',c0);
            cellArray[3].setPosition('r',r0+2);
            cellArray[3].setPosition('c',c0+1);
            direction = north;
         }
      }else if(direction == south){
         if(r0 - 2 >= 0 &&
            bd->getType(r0-2, c0-2) == 32 &&
            bd->getType(r0-2, c0-1) == 32 &&
            bd->getType(r0, c0-2) == 32){
            cellArray[0].setPosition('r',r0-2);
            cellArray[0].setPosition('c',c0-1);
            cellArray[1].setPosition('r',r0-2);
            cellArray[1].setPosition('c',c0-2);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0-2);
            cellArray[3].setPosition('r',r0);
            cellArray[3].setPosition('c',c0-2);
            direction = east;
         }
      }else if(direction == west){
         if(c0 + 2 < 11 &&
            bd->getType(r0-1, c0) == 32 &&
            bd->getType(r0-1, c0+2) == 32 &&
            bd->getType(r0, c0+2) == 32){
            cellArray[0].setPosition('r',r0);
            cellArray[0].setPosition('c',c0+2);
            cellArray[1].setPosition('r',r0-1);
            cellArray[1].setPosition('c',c0+2);
            cellArray[2].setPosition('r',r0-1);
            cellArray[2].setPosition('c',c0+1);
            cellArray[3].setPosition('r',r0-1);
            cellArray[3].setPosition('c',c0);
            direction = south;
         }
      }
}

//getShape
string JBlock::getShape(){
    return "J\nJJJ";
}
