# ifndef __CELL_H__
# define __CELL_H__
# include <iostream>
#include "window.h"

struct posn{
    int r,c;
};

class Cell{
   char cellType;                                                                     
   int blocknumber;
   int level;
   public:
    posn position;                                                            //cell position
      Cell();                                                                 //default constructor
      Cell(int r, int c, char type, int blocknum);                            //constructor
      void setPosition(char p, int n);                                        //change cell position
      int getPosition(char p) const;                                          //change cell position
      void setType(char type);                                                //change the type of cell
      void incrementPosition(char p);                                         //increase the cell position
      void decrementY();                                                      //decrease the cell position
      char getType() const;                                                   //get the cell type
      int getBlockNumber() const;                                             //get the number of block
      void draw(Xwindow *w);                                                  //draw the window
      void undraw(Xwindow *w);                                                //undraw the window
      bool operator == (Cell& old);                                           //whether two cells are equal
      void setCell(char type, int numblock);                                  //change cell
      Cell &operator=(const Cell& old);                                       //assignment operator
      friend std::ostream &operator<<(std::ostream &out, const Cell& c);      //cout operator
   };
   




# endif
