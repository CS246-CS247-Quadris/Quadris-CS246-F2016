#include "Include/board.h"
#include "Include/block.h"
#include "Include/Iblock.h"
#include "Include/Jblock.h"
#include "Include/Lblock.h"
#include "Include/Oblock.h"
#include "Include/Sblock.h"
#include "Include/Tblock.h"
#include "Include/Zblock.h"
#include "Include/window.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include<fstream>
using namespace std;

void command_function(string s, int intlen, Board*myboard ,int freq){                                                                             //comamnd:left,right,down...
    if(s.substr(intlen,3) == "lef"){                                                                                                              //left
      for(int i = 1; i <= freq; ++i){
        myboard->makeothermove("lef");
        if(myboard->getlevel() >= 3){
          myboard->makeothermove("do");                                                                                                           //down
        } 
      }
      cout << *myboard;                                                                                                                           //display board
    } else if (s.substr(intlen,2) == "ri" || s.substr(intlen,2) == "do" || s.substr(intlen,2) == "cl" || s.substr(intlen,2) == "co"){             //right, down, clockwise,counterclockwise
      for(int i = 1; i <= freq; ++i){
        myboard->makeothermove(s.substr(intlen,2));
        if(myboard->getlevel() >= 3){
          myboard->makeothermove("do");                                                                                                           //down
        }
      }  
      cout << *myboard;                                                                                                                          //display board 
    } else if(s.substr(intlen,2) == "dr") {                                                                                                      // drop
      for(int i = 1; i <= freq; ++i){
        myboard->drop();
       }
     } else if (s.substr(intlen,6) == "levelu"){                                                                                                 // levelup
       for(int i = 1; i <= freq; ++i){
         myboard->levelup();
       }
       cout << *myboard;                                                                                                                          //display board
     } else if(s.substr(intlen,6) == "leveld"){                                                                                                   // leveldown
       for(int i = 1; i <= freq; ++i){
         myboard->leveldown();
       }
       cout << *myboard;
     } else if(s == "I" || s == "J" || s == "L" || s == "O" || s == "S" || s == "T" || s == "Z"){                                                 // change blocks among I J L O S T Z
       const char * tmp = s.c_str();
       char c = tmp[0];
       myboard->change_current_block(c);
       cout << *myboard;                                                                                                                          //display board
     } else if (s.substr(intlen,2) == "no"){                                                                                                      // norandom
       if(myboard->getlevel() >= 3){
         string tmpf;
         cin >> tmpf;
         myboard->change_whether_readfile();
         myboard->change_ff(tmpf);
       }
     } else if (s.substr(intlen,2) == "ra"){                                                                                                       // random    
       if (myboard->getlevel() >= 3){
         myboard->change_whether_readfile();
       }
     } else if(s.substr(intlen,2) == "re"){                                                                                                       // restart
       for(int i = 1; i <= freq; ++i){
         myboard->restart();       
       }
       cout << *myboard;                                                                                                                          //display board
     }
     else {
       cout <<"Invalid Command!" << endl;
     }
     
}






int main (int argc, char *argv[]) {
  bool OnlyText = false;
  int seed = 0;
  int startlevel = 0;
  bool isfile = false;
  string file = "sequence.txt";
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-text") == 0) {
      OnlyText = true;
 //     cout << "text";
    } else if(strcmp(argv[i], "-seed") == 0){
      istringstream ss(argv[i+1]);
      ss >> seed;
 //     cout <<"seed";
    } else if(strcmp(argv[i], "-scriptfile") == 0){
      file = argv[i+1];
      isfile = true;
  //    cout << "file";
    } else if (strcmp(argv[i], "-startlevel") == 0){
      istringstream ss(argv[i+1]);
      ss >> startlevel;
  //    cout << "startleve";
    }

  }
  
  if (startlevel == 0){
    isfile = true;
  } else {
    isfile = false;
  }

  Board *myboard = new Board(OnlyText, seed, file, startlevel,isfile);
  cout << *myboard;
    
  // read command
  string s;
  int freq = 1;
  int intlen = 0;

  while(cin >> s){
  //get prex
    for(int i = 0; i < s.length(); ++i){
      if(s[i] >= '0' && s[i] <= '9'){
        intlen = i + 1;
      } else {
        break;
      }
    }
    if(intlen > 0) {
      string intstr = s.substr(0,intlen);
      istringstream ss(intstr);
      ss >> freq;
    }
    if(s.substr(intlen,2) == "se"){
        string sequence_file;
        cin >> sequence_file;
        ifstream myreadfile;
       myreadfile.open(sequence_file.c_str());
        while (!myreadfile.eof()){
          myreadfile >> s;
          command_function(s,intlen, myboard ,freq);
          freq = 1;
          intlen = 0;
        }
    }
    else{
      command_function(s,intlen, myboard ,freq);
    }
     freq = 1;
     intlen = 0;
  }
  delete myboard;
}
