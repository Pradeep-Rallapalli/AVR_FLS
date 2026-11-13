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

uint8_t FileSystem::getMatchingNodes(uint8_t key) {
  int j = 0;
  for(int i = 0; i < Constants::NODES_ARRAY_SIZE; i++) {
    if(nodes[i].parent == key && (nodes[i].name[0] != Constants::NULL_TERMINATOR)) {
      matchingNodes[j] = i;
      j++;
    }
  }
  return j;
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

/*
use current directory,
retrive all nodes with matching current directory
return to list 
*/



void FileSystem::list() {
  Serial.println(F("-----List-----"));

  Serial.print(F("|_"));
  Serial.println(nodes[currentDirectory].name);

  uint8_t matchingCount = getMatchingNodes(currentDirectory);

  for (uint8_t i = 0; i < matchingCount; i++) {
    uint8_t index = matchingNodes[i];

    if (index == currentDirectory) {
      continue;  // root is its own parent, don't list it under itself
    }

    Node& node = nodes[index];

    Serial.print(F("    |_"));
    Serial.print(node.name);
    if (node.type == T_DIRECTORY) {
      Serial.print('/');
    }
    Serial.println();
    delay(500);
  }

  Serial.println(F("--------------"));
}




