#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cell.h"
#include "board.h"
using namespace std;

enum Direction {east,west,north,south};                           //this is used to record which direction the block is towards to

class Board;

class Block{
    
protected:
      Direction direction;                                        // this is use to determine the position of each cell in the rotationArray.
	  Cell cellArray[4];                                        // A block is consist of 4 cells.
      char type;                                                  //this records the type of block,I,J,L,S,O,T,Z,
      int number;                                                 //this records the number of the current block is in the board 
      Board *bd;                                                  // pointer to the Board. The board is an observer for each block.
   public:
 
   int getBlock_Cell_Position(int which_cell, char p);            //gets the cell postion

    Block(char type, int number, Board* myboard);                 //Board constructor
    char getBlockType();                                          //get the type of Block
	   
      void left();                                                //move block to left
      void right();                                               //move block to right
      Direction getDirection();                                   //get the current block direction
      virtual void Clockwise()=0;                                 //Clockwise the block
      virtual void CounterClockWise()=0;                          //CounterClockWise the block
      void down();                                                //move block to down
      void drop();                                                //drop the block
      void draw(Xwindow *w);                                      //draw the block
      void undraw(Xwindow *w);                                    //undraw the block
      int getBlocknumber();                                       //get the number of block;


      virtual string getShape()= 0 ;                              //get the shape of block;

};

# endif
