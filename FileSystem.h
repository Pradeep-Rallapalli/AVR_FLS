#pragma once
#include "Constants.h"
#include "Node.h"

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

