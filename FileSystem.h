#pragma once
#include "Constants.h"

enum Type : uint8_t {T_FILE, T_DIRECTORY}; 

struct Node {
  char name[Constants::MAX_NAME_LENGTH + 1];
  uint8_t parent; 
  Type type;
};

class FileSystem {

public:
  FileSystem();
  void createFile(const char* fileName);
  void createDirectory();
  void list();
  void changeDirectory(char directoryName[Constants::MAX_NAME_LENGTH]);
  void deleteFile(char fileName[Constants::MAX_NAME_LENGTH]);
  void deleteDirectory(char fileName[Constants::MAX_NAME_LENGTH]);

private:
uint8_t getMatchingNodes(uint8_t key);
Node nodes[Constants::NODES_ARRAY_SIZE];
uint8_t matchingNodes[Constants::NODES_ARRAY_SIZE];
uint8_t currentDirectory;
uint8_t vacantIndex;
};

