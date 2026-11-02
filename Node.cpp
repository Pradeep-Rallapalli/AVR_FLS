#include "Node.h"

Node::Node(const char* fileNamePtr) {
    byte size = 0;

    while(fileNamePtr[size] != Constants::NULL_TERMINATOR) {
      size++;
    }

    this->fileNamePtr = malloc(size + 1 * sizeof(char));
    
    if (this->fileNamePtr == nullptr) {
        Serial.println(F("Error: File creation memory allocation FAILED!"));
        while(1); //Stop execution here 
    }

    for(int i = 0; i < size; i++) {
      this->fileNamePtr[i] = fileNamePtr[i];
    }
    this->fileNamePtr[size] = Constants::NULL_TERMINATOR;
    Serial.println(F("SUCCESS NEW FILE CREATED!"));
  }

Node::~Node() {
    free(fileNamePtr);
    this->fileNamePtr = nullptr;
  }