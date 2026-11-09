#pragma once
#include "Constants.h"

struct File {
  char fileName[Constants::MAX_NAME_LENGTH];
};

struct Directory {
  char directoryName[Constants::MAX_NAME_LENGTH];
  File* filesInDirectory[];
};

class FileSystem {

public:
  void createFile();
  void createDirectory();
  void list();
  void changeDirectory(char directoryName[Constants::MAX_NAME_LENGTH]);
  void deleteFile(char fileName[Constants::MAX_NAME_LENGTH]);
  void deleteDirectory(char fileName[Constants::MAX_NAME_LENGTH]);

};