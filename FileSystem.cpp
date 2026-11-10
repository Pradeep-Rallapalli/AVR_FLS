#include "FileSystem.h"

void createFile();
  void createDirectory();
  void list();
  void changeDirectory(char directoryName[Constants::MAX_NAME_LENGTH]);
  void deleteFile(char fileName[Constants::MAX_NAME_LENGTH]);
  void deleteDirectory(char fileName[Constants::MAX_NAME_LENGTH]);