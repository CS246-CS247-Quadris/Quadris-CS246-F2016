#include "Include/level1.h"
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


//level1 cstr
Level1::Level1(Board *otherboard, int number_block):Level(otherboard,number_block){}

//generate new block
Block* Level1::newBlock(){
    int RandomChoose;
    Block* next = NULL;
    RandomChoose = 1 + (rand() % 12);
    if(RandomChoose <= 2){
    	next = new IBlock('I',block_number,myboard);
    } else if(RandomChoose <= 4){
    	next = new JBlock('J',block_number,myboard);
    } else if(RandomChoose <= 6){
    	next = new LBlock('L',block_number,myboard);
    } else if(RandomChoose <= 8){
    	next = new OBlock('O',block_number,myboard);
    } else if(RandomChoose <= 9){
    	next = new SBlock('S',block_number,myboard);
    } else if(RandomChoose <= 10){
    	next = new ZBlock('Z',block_number,myboard);
    } else if(RandomChoose <= 12){
    	next = new TBlock('T',block_number,myboard);
    }
    
    return next;
}
