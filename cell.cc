# include <iostream>
# include "Include/cell.h"
using namespace std;
//assignemnt operator
Cell &Cell::operator=(const Cell& old){
   cellType = old.cellType;
   position.r = old.position.r;
   position.c = old.position.c;
   blocknumber = old.blocknumber;
   return *this;
}

//get blocknum
int Cell::getBlockNumber() const{
  return blocknumber;
}

//cell cstr
Cell::Cell(){
    position.r = 0;
    position.c = 0;
    cellType = 32;
    blocknumber = 0;
}

//cell cstr
Cell::Cell(int r, int c, char type, int blocknum){
  position.r=r;
  position.c=c;
  cellType=type;
  blocknumber=blocknum;
}

//get cell position
int Cell::getPosition(char p) const{
  if (p == 'r'){
    return position.r;
  }
  else if ( p == 'c'){
    return position.c;
  }
}

//change cell position
void Cell::setPosition(char p, int n){
  if (p == 'r'){
    position.r = n;
  }
  else if ( p == 'c'){
    position.c = n;
  }
}

//get cell type
char Cell::getType() const{
   return cellType;
   }


//change cell   
void Cell::setCell(char type, int numblock){
   cellType = type;
   blocknumber = numblock;
}

//increase cell position
void Cell::incrementPosition(char p){
  if ( p == 'r'){
    position.r++;
  }
  else if ( p == 'c'){
    position.c++; 
  }
}

//decrease cell position
void Cell::decrementY(){
   position.c--;
   }

//cout operator
ostream &operator<<(ostream &out, Cell& c){
    out << c.getType();
    return out;
}

//change cell type
void Cell::setType(char type){
  cellType = type;
}

//draw the window
void Cell::draw(Xwindow *w){
    int topleft_x = 30;
        int topleft_y = 40;
  if(cellType == 'I'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Magenta);
  }else if(cellType == 'J'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Blue);
  }else if(cellType == 'O'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30,30, Xwindow::Orange);
  }else if(cellType == 'L'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Yellow);
  }else if(cellType == 'S'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Brown);
  }else if(cellType == 'T'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Cyan);
  }else if(cellType == 'Z'){
        w->fillRectangle(topleft_x + 4+34*position.c, topleft_y + 4+34*position.r, 30, 30, Xwindow::Red);
  } 
}

//undraw window
void Cell::undraw(Xwindow *w){
   w->fillRectangle(30+30*position.c, 40+30*position.r,30, 30, Xwindow::White);
}

//equal operator
bool Cell::operator ==  (Cell& old){
  return (cellType == old.cellType && position.r == old.position.r && position.c == old.position.c && blocknumber == old.blocknumber);
}

