#pragma once
#include <Arduino.h>

namespace Constants {
  
  constexpr uint8_t MAX_NAME_LENGTH= 15;
  constexpr uint8_t MAX_INPUT_SIZE = 32;
  constexpr char NULL_TERMINATOR = '\0';
  
  //Update if new commands are added
  constexpr uint8_t MAX_COMMAND_SIZE = 6;
}