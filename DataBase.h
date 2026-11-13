#pragma once
#include <Arduino.h>
#include <EEPROM.h>
#include "Constants.h"
#include "Node.h"   

class DataBase {
public:
  // Fills nodes from EEPROM. On a blank chip, creates root first.
  // Returns false if stored data looks corrupt.
  bool loadAll(Node* nodes);
  
  uint8_t countUsed(const Node* nodes) const;

  // Writes one slot. Returns false if the request is invalid.
  bool saveNode(uint8_t index, const Node& node);


private:
  static int addressOf(uint8_t index) { return index * sizeof(Node); }
  static bool isValid(const Node& node);
  void createRoot(Node& root);
};