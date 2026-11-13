#pragma once
#include <Arduino.h>
#include <EEPROM.h>
#include "Constants.h"
#include "Node.h"   // wherever Node and Type live

class DataBase {
public:
  // Fills nodes from EEPROM. On a blank chip, creates root first.
  // Returns false if stored data looks corrupt.
  bool loadAll(Node (&nodes)[Constants::NODES_ARRAY_SIZE]);

  // Writes one slot. Returns false if the request is invalid.
  bool saveNode(uint8_t index, const Node& node);

  // Number of non-free slots in the array.
  uint8_t countUsed(const Node (&nodes)[Constants::NODES_ARRAY_SIZE]) const;

private:
  static int addressOf(uint8_t index) { return index * sizeof(Node); }
  static bool isValid(const Node& node);
  void createRoot(Node& root);
};