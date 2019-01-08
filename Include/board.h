#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include "block.h"
#include <iostream>
#include <fstream>
#include "window.h"
#include <vector>
#include <string>
#include "level.h"
using namespace std;

class Block;
class Level;


class Board{
    static bool seeded;                                                                                                     //record whether the seed is put
    static int HighScore;                                                                                                   //record the high score of the current game
    
    Cell **theboard;                                                                                                        //record the board which is 11*18
    bool startplay;                                                                                                         //record the game status
    bool whether_read_file;                                                                                                 //whether read block from file
    bool textonly;                                                                                                          //whether display the window
    int level;                                                                                                              //record the level of current game
    int score;                                                                                                              //record the current score
    int seed;                                                                                                               //record the seed value if seed is put
    int numblock;                                                                                                           //record the current number of block
    

    ifstream ff;                                                                                                            //read from the input file
    vector<int> array_level;                                                                                                //record the level of each block
    vector<bool> array_cleared;                                                                                             //record whether the block is cleared
    
    Block *currentBlock;                                                                                                     //record the currentBlock
    Block *nextBlock;                                                                                                        //record nextBlock
    Xwindow* window;                                                                                              
    
    Level *levelclass;                                                                                                       //record the class level


    public:
       ~Board();                                                                                                             //destructor
       Board(bool textonly = false, int seed = 10, std::string file = "", int startlevel = 0, bool is_file=false);           //contructor
       Block* genNextBlock();                                                                                                //generate the next block
       bool isFullRow(int n);                                                                                                //determine whether nth row is a full row
       void clearRow(int n);                                                                                                 //clear row
       bool win();                                                                                                           //determine whether I win
       bool fail();                                                                                                          //determine whether I lose
       void change_ff(string file);                                                                                          //change readable file 
      int getlevel ();                                                                                                       //get the current level
      void setCell(int r, int c, char type, int numblock);                                                                   //set the cell
      friend std::ostream &operator<<(std::ostream &out, const Board &bd);                                                   //big 5 operator
       void drop();                                                                                                          //drop block
       void levelup();                                                                                                       //levelup
       void leveldown();                                                                                                     //leveldown
       void restart();                                                                                                       //restart the game
       void change_whether_readfile();                                                                                       //change nextBlock whether read from file
       void change_current_block(char block_type);                                                                           //change current block 
       void makeothermove(string command);                                                                                   //change move of block
       char getType(int r, int c);                                                                                           //get the cell type on (r,c)
       bool iscleared(int i);                                                                                                //check whether the block is cleared
       void clearwindow();                                                                                                   //clear the window

};
# endif
