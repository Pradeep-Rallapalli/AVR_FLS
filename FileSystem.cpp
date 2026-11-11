#include "FileSystem.h"
#include "Constants.h"



FileSystem::FileSystem() {
  currentDirectory = 0;
  Node root;
  strcpy(root.name, "/");
  root.parent = 0;
  root.type = T_DIRECTORY;
  nodes[currentDirectory] = root;
  vacantIndex = 1;
}



void FileSystem::createFile(const char* fileName) {

  Node newFile;
  strncpy(newFile.name, fileName, Constants::MAX_NAME_LENGTH);
  newFile.name[Constants::MAX_NAME_LENGTH] = Constants::NULL_TERMINATOR;
  newFile.parent = currentDirectory;
  newFile.type = T_FILE;

  
  if(vacantIndex < Constants::NODES_ARRAY_SIZE) {
    nodes[vacantIndex] = newFile;
    vacantIndex++;
  }

}

void FileSystem::list() {
  Serial.println("-----List-----");
  for(int i = 0; i < Constants::NODES_ARRAY_SIZE; i++) {
    Serial.println(nodes[i].name);
  }

  Serial.println("--------------");
}



