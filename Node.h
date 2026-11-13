#pragma once
#include "Constants.h"

enum Type : uint8_t {T_FILE, T_DIRECTORY, T_FREE = 0xFF}; 

struct Node {
  char name[Constants::MAX_NAME_LENGTH + 1];
  uint8_t parent; 
  Type type;
};