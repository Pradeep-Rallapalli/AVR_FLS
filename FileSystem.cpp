#include "FileSystem.h"
#include "Constants.h"


/*
Refactor:
- Database creates root. Pass it nodes array.
- set vacant index to not root 
*/
FileSystem::FileSystem() {
  if(!db.loadAll(nodes)) {
    Serial.println(F("DB to Memory load failure! Corrupt DB Data."));
    Serial.println(F("Program Yeilding."));
    while(1);
  }
  currentDirectory = 0;
  vacantIndex = 1;

  Serial.println();
  Serial.print(F("File system ready. Storage used: %"));
  Serial.print(((float)db.countUsed(nodes)/Constants::NODES_ARRAY_SIZE) * 100);
  Serial.println();

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
    if(!db.saveNode(vacantIndex, newFile)) {
      Serial.println(F("DB Save Error!"));
    }
    vacantIndex++;
  }

  Serial.println();
  Serial.print("file ");
  Serial.print(fileName);
  Serial.print(" saved!");
  Serial.println();
}

 
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
  }

  Serial.println(F("--------------"));
}




