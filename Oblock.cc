#include "Include/Oblock.h"
#include <iostream>
#include <vector>
using namespace std;
/* O-BLOCK METHODS */

//OBlock cstr
OBlock::OBlock(char type, int number,Board* myboard) :Block(type,number,myboard){
    cellArray[0] = Cell(3,0,'O',number);
     cellArray[1] = Cell(3,1,'O',number);
     cellArray[2] = Cell(4,0,'O',number);
     cellArray[3] = Cell(4,1,'O',number);
}

//Clockwise
void OBlock::Clockwise(){}
//CounterClockWise
void OBlock::CounterClockWise(){}
//getShape
string OBlock::getShape(){
    return "OO\nOO";
}
