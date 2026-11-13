#include "DataBase.h"


bool DataBase::isValid(const Node& node) {
  if (node.type != T_FILE && node.type != T_DIRECTORY) return false;
  if (node.parent >= Constants::NODES_ARRAY_SIZE) return false;
  return true;
}

void DataBase::createRoot(Node& root) {
  memset(&root, 0, sizeof(Node));
  root.name[0] = '/';
  root.parent = 0;
  root.type = T_DIRECTORY;
  EEPROM.put(addressOf(0), root);
}

bool DataBase::loadAll(Node* nodes) {
  for (uint8_t i = 0; i < Constants::NODES_ARRAY_SIZE; i++) {
    EEPROM.get(addressOf(i), nodes[i]);
    nodes[i].name[Constants::MAX_NAME_LENGTH] = Constants::NULL_TERMINATOR;
  }

  // Blank chip: slot 0 reads 0xFF, so the whole EEPROM is "free".
  if (nodes[0].type == T_FREE) {
    createRoot(nodes[0]);
  }

  // Root must be a directory that is its own parent.
  if (nodes[0].type != T_DIRECTORY || nodes[0].parent != 0) return false;

  for (uint8_t i = 1; i < Constants::NODES_ARRAY_SIZE; i++) {
    if (nodes[i].type == T_FREE) continue;
    if (!isValid(nodes[i])) return false;
  }
  return true;
}

bool DataBase::saveNode(uint8_t index, const Node& node) {
  if (index >= Constants::NODES_ARRAY_SIZE) return false;
  if (index == 0 && node.type != T_DIRECTORY) return false;  // root is protected
  EEPROM.put(addressOf(index), node);  // put() uses update(): only changed bytes get written
  return true;
}

uint8_t DataBase::countUsed(const Node* nodes) const {
  uint8_t used = 0;
  for (uint8_t i = 0; i < Constants::NODES_ARRAY_SIZE; i++) {
    if (nodes[i].type != T_FREE) used++;
  }
  return used;
}