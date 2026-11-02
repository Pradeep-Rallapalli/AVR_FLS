#pragma once 
#include "Constants.h"

class Node {
  private:
  
  char* fileNamePtr;
  
  public:
  Node(const char* fileNamePtr);

  ~Node();
};