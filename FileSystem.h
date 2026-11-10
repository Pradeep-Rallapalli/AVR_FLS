#pragma once
#include "Constants.h"

struct Node {
  char name[Constants::MAX_NAME_LENGTH + 1];
  uint8_t parent; 
};

class FileSystem {

public:
  void createFile();
  void createDirectory();
  void list();
  void changeDirectory(char directoryName[Constants::MAX_NAME_LENGTH]);
  void deleteFile(char fileName[Constants::MAX_NAME_LENGTH]);
  void deleteDirectory(char fileName[Constants::MAX_NAME_LENGTH]);

private:
Node nodes[32];
int currentDirectory;
};