#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>

class View {

  protected:
    const int gridSize;
  public:
    View(int n);
    
 /*
  * The Controller calls notify to update the (row,column) location to be ch
  */
 virtual void notify(int row, int column, int update) = 0;

 virtual void print(std::ostream &out) const = 0;
    
 virtual ~View() = 0;
};

#endif

