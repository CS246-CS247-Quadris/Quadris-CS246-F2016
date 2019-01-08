# include "Include/cell.h"
# include "Include/block.h"
# include <iostream>
# include <vector> 
using namespace std;

//constructor
Block::Block(char type, int number,Board* myboard): type(type), number(number),bd(myboard){
   if (type == 'I') {
    direction = east;
   } else if (type == 'T') {
    direction = south;
   } else {
    direction = north;
   }
   for(int i= 0; i < 4 ; ++i){
      cellArray[i] = Cell(); 
   }
}

//get the cell position
int Block::getBlock_Cell_Position(int which_cell, char p){
    return cellArray[which_cell].getPosition(p);
}



//get the block type   
char Block::getBlockType(){
   return type;
}   

//get the block direction   
Direction Block::getDirection(){
   return direction;
}   
   

//move block to left
void Block::left(){
   bool can_left = true;
   for(int i = 0; i < 4; ++i){
      if((cellArray[i].getPosition('c')- 1) < 0){
         can_left = false;
         break;
      }
   }
   if(can_left){
      for(int i =0; i < 4; ++i){
         cellArray[i].decrementY();
      }
   }
}

//move block to right         
void Block::right(){
   bool can_right = true;
   for(int i = 0; i < 4; ++i){
      if((cellArray[i].getPosition('c') + 1) > 10){
         can_right = false;
         break;
      }

   }
   if (can_right){
      for(int i =0; i < 4; ++i){
         cellArray[i].incrementPosition('c');
      }
   }
}

//move block to down
void Block::down(){
   bool can_down = true;
   for(int i = 0; i < 4; ++i){
      if((cellArray[i].getPosition('r') + 1) > 17){
         can_down = false;
         break;
      }
      if(bd->getType(cellArray[i].getPosition('r') + 1, cellArray[i].getPosition('c')) != 32){
         can_down = false;
         break;
      }

   }
   if (can_down){
      for(int i =0; i < 4; ++i){
         cellArray[i].incrementPosition('r');
      }
   }
}

//dorp block
void Block::drop(){
   int markadd = 0;
   Cell tmp = cellArray[0];
   this->down();
   while (!(tmp == cellArray[0])){
       tmp = cellArray[0];
       this->down();
   }

}

//get block number
int Block::getBlocknumber(){
  return number;
}

//draw block
void Block::draw(Xwindow *w){
   if(w != 0){
     for(int i = 0; i <4; ++i){
      cellArray[i].draw(w);
     }
   }
}

//undraw block
void Block::undraw(Xwindow *w){
  if(w != 0){
    for(int i = 0; i <4; ++i){
      cellArray[i].undraw(w);
    }
  }
}
