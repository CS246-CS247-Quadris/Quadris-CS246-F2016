#include "Include/board.h"
#include "Include/window.h"
#include "Include/block.h"
#include "Include/Iblock.h"
#include "Include/Jblock.h"
#include "Include/Lblock.h"
#include "Include/Oblock.h"
#include "Include/Sblock.h"
#include "Include/Tblock.h"
#include "Include/Zblock.h"
#include "Include/level1.h"
#include "Include/level2.h"
#include "Include/level3.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;


int Board::HighScore = 0;
bool Board::seeded = false;

//constructor
Board::Board(bool textonly, int seed, string file, int startlevel,bool is_file): textonly(textonly), startplay(false),seed(seed),ff(file.c_str()), level(startlevel),whether_read_file(is_file){
   theboard = new Cell* [18];
   numblock = 0;
   for (int i = 0; i < 18; ++i){
      Cell* theCell = new Cell[11];
      for (int j = 0; j < 11; ++j) {
         theCell[j].setPosition('r',i);
         theCell[j].setPosition('c',j);
      }
      theboard[i] = theCell;
   }
   if(textonly == true){
      window = 0;
   } else {
     window = new Xwindow(450,1000);
   }
   currentBlock = genNextBlock();
   nextBlock = genNextBlock();
}

//destructor
Board::~Board(){
  for (int i = 0; i < 18; ++i) {
	delete [] theboard[i];
  }
  delete [] theboard;
  delete window;
  delete currentBlock;
  delete nextBlock;
  delete levelclass;
}


//get level
int Board::getlevel(){
  return level;
}

//clearRow
void Board::clearRow(int n){
  for(int i = n; i >= 4; --i){
    for(int j = 0; j < 11; ++j){
       theboard[i][j] = theboard[i-1][j];
       theboard[i][j].incrementPosition('r');
    }
  }
  for(int i = 0; i < 4; ++i){
    for(int j = 0; j < 11; ++j){
       theboard[i][j] = Cell(i,j,32,0);
    }
  }
}


//generate next block
Block * Board::genNextBlock(){
  char c;
  int RandomNum;
  numblock += 1;
  Block* next = NULL;
  switch(level){
    case 1:
      levelclass = new Level1(this,numblock);
      break;
    case 2:
      levelclass = new Level2(this,numblock);
      break;
    case 3:
      levelclass = new Level3(this,numblock);
      break;
    default:
      levelclass = NULL;
  }

  if(whether_read_file){
  	ff >> c;
    if (!ff.eof()){
    switch(c){
      case 'I' :
        next = new IBlock(c,numblock,this);
        break;
      case 'J' :
        next = new JBlock(c,numblock,this);
        break;
      case 'L' :
        next = new LBlock(c,numblock,this);
        break;
      case 'O' :
        next = new OBlock(c,numblock,this);
        break;
      case 'S' :
        next = new SBlock(c,numblock,this);
        break;
      case 'T' :
        next = new TBlock(c,numblock,this);
        break;
      case 'Z' :
        next = new ZBlock(c,numblock,this);
        break;
    }	
  }
  else {
    next = levelclass->newBlock();
    change_whether_readfile();
  }
  }

  else{
    if(!seeded){
       srand(seed);
       seeded = true;
    }
    next = levelclass->newBlock();
  }
  array_level.push_back(level);
  array_cleared.push_back(false);
  return next;
}


//change read file
void Board::change_ff(string file){
      ff.close();
      ff.open(file.c_str());
}

//set cellStatus
void Board::setCell(int r, int c, char type, int numblock){
   theboard[r][c].setCell(type, numblock);
}

//check whether row is full
bool Board::isFullRow(int n){
   bool result = true;
   for (int i = 0; i < 11; ++i){
      if (theboard[n][i].getType() == 32){
         result = false;
         break;
      }
    }
   return result;
}

//check whether win
bool Board::win(){
    bool won = true;
    for (int i = 0; i < 18 ; ++i){
       for(int j = 0; j < 11; ++j){
          if (theboard[i][j].getType() != 32){
             won = false;
             }
          }
       }
    return won;
}

//check whether fail
bool Board::fail(){
   bool lost = false;
   char t = nextBlock->getBlockType();
   char t30 = theboard[3][0].getType();
   char t31 = theboard[3][1].getType();
   char t32 = theboard[3][2].getType();
   char t33 = theboard[3][3].getType();
   char t40 = theboard[4][0].getType();
   char t41 = theboard[4][1].getType();
   char t42 = theboard[4][2].getType();
 
   switch(t) {
     case 'I' :
       if (t30 != 32 || t31 != 32 || t32 != 32 || t33 != 32){
           lost = true;
       }
       break;
     case 'J' :
      if (t30 != 32 || t40 != 32 || t41 != 32 || t42 != 32){
           lost = true;
      }
      break; 
     case 'L' :    
       if (t32 != 32 || t40 != 32 || t41 != 32 || t42 != 32){
           lost = true;
       }
       break;  
     case 'O' :
       if (t30 != 32 || t31 != 32 || t40 != 32 || t41 != 32){
           lost = true;
       }
       break;
     case 'S' :
       if (t31 != 32 || t32 != 32 || t40 != 32 || t41 != 32){
           lost = true;
       }   
       break;
     case 'Z' :
       if (t30 != 32 || t31 != 32 || t41 != 32 || t42 != 32){
           lost = true;
       }
       break;   
     case 'T' :
       if (t30 != 32 || t31 != 32 || t32 != 32 || t41 != 32){
           lost = true;
       }
       break;
   }
   return lost;
}

//drop
void Board::drop(){
    clearwindow();
    currentBlock->drop();
    for(int i = 0; i < 4; ++i){
      int row = currentBlock->getBlock_Cell_Position(i, 'r');
      int col = currentBlock->getBlock_Cell_Position(i, 'c');
     this->setCell(row, col, currentBlock->getBlockType(), currentBlock->getBlocknumber());
   }
    int markadd = 0;
    int totalclear = 0;
   for(int i = 0; i < 18; ++i){
     if(this->isFullRow(i)){
        this->clearRow(i);
        --i;
        totalclear += 1;
     }
   }
   if(totalclear >= 1){
      markadd += (this->getlevel() + totalclear) * (this->getlevel() + totalclear);
   }
   for(int i = 0; i < this->numblock; ++i){
      if(this->array_cleared[i] == false){
         if(this->iscleared(i)){
           markadd += (this->array_level[i] + 1) * (this->array_level[i] + 1);
           this->array_cleared[i] = true;
         }
      }
   }
    score = score + markadd;
    if(score > HighScore){
       HighScore = score;
    }
    delete currentBlock;
    currentBlock = nextBlock;
    nextBlock = genNextBlock();
    cout << *this;
    if(fail()){
      delete currentBlock;
      delete nextBlock;
      cout << "Game Over" << endl;
      if(window != 0){
        window->drawString(30, 750, "Game Over", Xwindow::Brown);
      }
    }
    if(win()){
      delete currentBlock;
      delete nextBlock;
      cout << "Congratulations!" << endl;
      if(window != 0){
        window->drawString(30, 750, "Congdulation", Xwindow::Brown);
      }
    }          
}

//clearwindow
void Board::clearwindow(){
  if(window != 0){
    window->fillRectangle(0,0,1000,1000,Xwindow::White);
  }
}

//levelup
void Board::levelup(){
    if(level == 4){
        cout << "CANNOT LEVEL UP ANYMORE!" << endl;
    }else {      
            level = level + 1;
    }
}

//leveldown
void Board::leveldown(){
    if(level == 0){
        cout << "CANNOT LEVEL DOWN ANYMORE!" << endl;
    }else {
            level = level - 1;
            }
}

//restart Game
void Board::restart(){
    if(score > HighScore) HighScore = score;
    score = 0;
    numblock = 0;
    for(int i = 0; i < 18; ++i){
        for(int j = 0; j < 11 ;++j){
            theboard[i][j].setType(32); 
        }
    }
    clearwindow();
    array_level.clear();
    array_cleared.clear();
    currentBlock = genNextBlock();
    nextBlock = genNextBlock();
}


//cout operator
ostream &operator<<(ostream &out, const Board &bd){
    out << "Level:      " << bd.level << endl;
    out << "Score:      " << bd.score << endl;
    out << "Hi Score:   " << bd.HighScore << endl;
    out << "-------------" << endl;
    for(int i = 0; i < 18; ++i){
      out << "|";
        for(int j = 0; j < 11; ++j){
          if(i == bd.currentBlock->getBlock_Cell_Position(0,'r') && j == bd.currentBlock->getBlock_Cell_Position(0,'c')){
            out << bd.currentBlock->getBlockType();
          }
          else if(i == bd.currentBlock->getBlock_Cell_Position(1,'r') && j == bd.currentBlock->getBlock_Cell_Position(1,'c')){
            out << bd.currentBlock->getBlockType();
          }
          else if(i == bd.currentBlock->getBlock_Cell_Position(2,'r') && j == bd.currentBlock->getBlock_Cell_Position(2,'c')){
            out << bd.currentBlock->getBlockType();
          }
          else if(i == bd.currentBlock->getBlock_Cell_Position(3,'r') && j == bd.currentBlock->getBlock_Cell_Position(3,'c')){
            out << bd.currentBlock->getBlockType();
          }
          else {
            out << bd.theboard[i][j].getType();
          }
        }
        out << "|";
        out << endl;
    }
    out << "-------------" << endl;
    out << "Next:" << endl;
    string nextBlockShape = bd.nextBlock->getShape();
    out << nextBlockShape;
    out << endl;
    if(bd.window != 0){
        int gridsize = 30;
        int barwidth =4;
        int topleft_x = 30;
        int topleft_y = 40;
        int vbar = 18 * gridsize + 19 * barwidth;
        int hbar = 11 * gridsize + 12 * barwidth;
        (bd.window)->fillRectangle(0, 0, 500, 1300, Xwindow::White);
       for (int i = 0; i <= 11; i++) {
        (bd.window)->fillRectangle(topleft_x + (gridsize + barwidth)*i, topleft_y, barwidth, vbar, Xwindow::Black);
             }
       for (int i = 0; i <= 18; i++) {
         (bd.window)->fillRectangle(topleft_x, topleft_y + (gridsize + barwidth)*i, hbar, barwidth, Xwindow::Black);
       }
      
      for (int r = 0; r< 18; r++){
        for (int c = 0; c<11; c++ ){
          char cellStatus = bd.theboard[r][c].getType();        
          switch (cellStatus) {
                           case 'T':
                            (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Cyan);
                            break;
                            case 'L':
                            (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Yellow);
                              break;
                             case 'J':
                              (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Blue);
                              break;
                            case 'S':
                           (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Brown);
                               break;
                          case 'Z':
                         (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Red);
                          break;
                          case 'I':
                          (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Magenta);
                          break;
                          case 'O':
                        (bd.window)->fillRectangle(topleft_x + c*(gridsize+ barwidth) + barwidth, topleft_y + r*(gridsize + barwidth) + barwidth, gridsize, gridsize, Xwindow::Orange);
                          break;
                                }
                                }
          }     
       ostringstream s1;
       s1 << bd.level;
       ostringstream s2;
       s2 << bd.score;
       ostringstream s3;
       s3 << bd.HighScore;
       bd.window->drawString(00, 10, "Level:", Xwindow::Black);
       bd.window->drawString(100, 10, s1.str(), Xwindow::Black);
       bd.window->drawString(00, 25, "Score:", Xwindow::Black);
       bd.window->drawString(100, 25, s2.str(), Xwindow::Black);
       bd.window->drawString(00, 38, "Hi Score:", Xwindow::Black);
       bd.window->drawString(120, 40, s3.str(), Xwindow::Black);
       bd.window->drawString(30, 45, "----------------------------------------------------------", Xwindow::Black);
       
    bd.currentBlock->draw(bd.window);

       bd.window->drawString(30, 800, "----------------------------------------------------------", Xwindow::Black);
       bd.window->drawString(30,895, "Next:" ,Xwindow::Black);
       if(bd.nextBlock->getBlockType() == 'I'){
          bd.window->fillRectangle(30, 910, 120,30, Xwindow::Magenta);
       }else if(bd.nextBlock->getBlockType() == 'J'){
          bd.window->fillRectangle(30, 910, 30,30, Xwindow::Blue);
          bd.window->fillRectangle(30, 940, 90,30, Xwindow::Blue);
       }else if(bd.nextBlock->getBlockType() == 'L'){
          bd.window->fillRectangle(90, 910, 30,30, Xwindow::Yellow);
          bd.window->fillRectangle(30, 940, 90,30, Xwindow::Yellow);
       }else if(bd.nextBlock->getBlockType() == 'O'){
          bd.window->fillRectangle(30, 910, 60,60, Xwindow::Orange);
       }else if(bd.nextBlock->getBlockType() == 'S'){
          bd.window->fillRectangle(70, 910, 60,30, Xwindow::Brown);
          bd.window->fillRectangle(30, 940, 60,30, Xwindow::Brown);
       }else if(bd.nextBlock->getBlockType() == 'Z'){
          bd.window->fillRectangle(30, 910, 60,30, Xwindow::Red);
          bd.window->fillRectangle(60, 940, 60,30, Xwindow::Red);
       }else if(bd.nextBlock->getBlockType() == 'T'){
          bd.window->fillRectangle(30, 910, 90,30, Xwindow::Cyan);
          bd.window->fillRectangle(60, 940, 30,30, Xwindow::Cyan);
       }

    }

    return out;
}

//get type
char Board::getType(int r, int c){
  return theboard[r][c].getType();
}

//check whether is cleared
bool Board::iscleared(int i){
  bool result = true;
  for(int r = 0; r < 18; ++r){
     for(int c = 0; c < 11; ++c){
      if(theboard[r][c].getBlockNumber() == i){
        result = false;
      }
     }
  }
  return result;
}

//change block is generated from file
void Board::change_whether_readfile(){
  whether_read_file=!whether_read_file;
}

//change currentBlock
void Board::change_current_block(char block_type){
  Block* next = NULL;
  numblock--;
  if ( block_type == 'I'){
    next = new IBlock(block_type,numblock,this);
  } else if ( block_type == 'J'){
    next = new JBlock(block_type,numblock,this);
  } else if ( block_type == 'L'){
    next = new LBlock(block_type,numblock,this);
  } else if ( block_type == 'O'){
    next = new OBlock(block_type,numblock,this);
  } else if ( block_type == 'S'){
    next = new SBlock(block_type,numblock,this);
  } else if ( block_type == 'T'){
    next = new TBlock(block_type,numblock,this);
  } else if ( block_type == 'Z'){
    next = new ZBlock(block_type,numblock,this);
  }
  if ( currentBlock !=  NULL){
    delete currentBlock;
  }
  currentBlock= next;
  numblock++;
}

//change block
void Board::makeothermove(string command){
  bool can = true;
  currentBlock->undraw(window);
  if (command == "lef"){
    for (int i = 0; i < 4; ++i){
        if (this->getType(currentBlock->getBlock_Cell_Position(i, 'r'), currentBlock->getBlock_Cell_Position(i, 'c') - 1) != 32){
          can = false;
          break;
        }
    }
    if (can){
    currentBlock->left();
    }
    }
    else if (command == "ri"){
      for (int i = 0; i < 4; ++i){
        if (this->getType(currentBlock->getBlock_Cell_Position(i, 'r'), currentBlock->getBlock_Cell_Position(i, 'c') + 1) != 32){
          can = false;
          break;
        }
    }
    if (can){
      currentBlock->right();
    }
    }
    else if (command == "do"){
         for (int i = 0; i < 4; ++i){
        if (this->getType(currentBlock->getBlock_Cell_Position(i, 'r')+1, currentBlock->getBlock_Cell_Position(i, 'c')) != 32){
          can = false;
          break;
        }
      }
      if(can){
      currentBlock->down();
      }
    }
    else if (command == "cl"){
      currentBlock->Clockwise();
    }
    else if (command == "co"){
      currentBlock->CounterClockWise();
    }
  currentBlock->draw(window);
}
