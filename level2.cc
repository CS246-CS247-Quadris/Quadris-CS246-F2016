#include "Include/level2.h"
#include "Include/block.h"
#include "Include/Iblock.h"
#include "Include/Oblock.h"
#include "Include/Zblock.h"
#include "Include/Lblock.h"
#include "Include/Jblock.h"
#include "Include/Sblock.h"
#include "Include/Tblock.h"
#include <cstdlib>

using namespace std; 

//level2 cstr
Level2::Level2(Board *otherboard, int number_block):Level(otherboard,number_block){}


//generate new block
Block* Level2::newBlock(){
    int RandomChoose;
    Block* next = NULL;
    RandomChoose = 1 + (rand() % 7);
    if(RandomChoose <= 1){
      next = new IBlock('I',block_number,myboard);
    } else if(RandomChoose <= 2){
      next = new JBlock('J',block_number,myboard);
    } else if(RandomChoose <= 3){
      next = new LBlock('L',block_number,myboard);
    } else if(RandomChoose <= 4){
      next = new OBlock('O',block_number,myboard);
    } else if(RandomChoose <= 5){
      next = new SBlock('S',block_number,myboard);
    } else if(RandomChoose <= 6){
      next = new ZBlock('Z',block_number,myboard);
    } else if(RandomChoose <= 7){
      next = new TBlock('T',block_number,myboard);
    }
    
    return next;
}
