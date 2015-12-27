#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <sstream>
#include "view.h"

class TextDisplay : public View {
  int **theDisplay;          //the n x n display , I changed return type to int for consistency
  
 public:
  TextDisplay(int n); //one arg constructor where the parameter is the gridSize

  ~TextDisplay(); //dtor
  
  /*
   * The Controller calls notify to update the (row,column) location to be update
   */
  virtual void notify(int row, int column, int update);

  /*
   * Prints the grid as specified in the assignment specification.
   */
  virtual void print(std::ostream &out) const ;
};

#endif

