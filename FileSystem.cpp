#include "FileSystem.h"
#include "Constants.h"

/*struct Node {
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
*/

FileSystem::FileSystem() {
  currentDirectory = 0;
  Node root;
  strcpy(root.name, "/");
  root.parent = 0;
  root.type = DIRECTORY;
  nodes[currentDirectory] = root;
}

uint8_t isThereSpace(const Node& nodeArray) {
  for(int i = 0; i < Constants::NODES_ARRAY_SIZE; i++) {
    if(nodeArray[i] == 0) {
      return i;
    }
  }
  return Constants::NODES_ARRAY_SIZE;
}

void FileSystem::createFile(const char* fileName) {

  Node newFile;
  strncpy(newFile.name, fileName, Constants::MAX_NAME_LENGTH);
  newFile.name[Constants::MAX_NAME_LENGTH] = Constants::NULL_TERMINATOR;
  newFile.parent = currentDirectory;
  newFile.type = FILE;

  uint8_t freeIndex = isThereSpace(nodes);
  if(freeIndex < Constants::NODES_ARRAY_SIZE) {
    nodes[freeIndex] = newFile;
  }

}



