#ifndef ALIGNMENT_H
#define ALIGNMENT_H

// dynprog.h - declaration file for Red-Black Tree class

#include <vector>
#include <string>
using namespace std ;

#include "table.h"


class Alignment {

public:

  // Constructor
  Alignment() ;

  // Routine to initialize table
  void initialize(string, string);

  // Return the Levenshtein distance
  int distance(void);

  // Print the sequence alignment
  //void print_alignment(void);
  
private:
  table tab;
  string x,y;
} ;

#endif
