#include "CommandProcessor.h"
#include "Constants.h"

struct KeyValuePair {
    const char *key;
    void (CommandProcessor::*funcPtr)(void);
  };

const char cd_str[] PROGMEM = "cd";
const char ls_str[] PROGMEM = "ls";
const char mkdir_str[] PROGMEM = "mkdir";
const char nano_str[] PROGMEM = "nano";

  const KeyValuePair commandMap[] PROGMEM = {
    {cd_str, &CommandProcessor::changeDirectory},
    {ls_str, &CommandProcessor::list},
    {mkdir_str, &CommandProcessor::createDirectory},
    {nano_str, &CommandProcessor::createFile}
  };

const uint8_t mapSize = sizeof(commandMap) / sizeof(KeyValuePair);

void extractCommand(const char* receivedBytes, char* extractedCommand, char* extractedArgument, bool& didExtract) {
  uint8_t i = 0;
    for(i; i < Constants::MAX_COMMAND_SIZE; i++) {
        if(receivedBytes[i] == Constants::NULL_TERMINATOR || receivedBytes[i] == ' ') {
            extractedCommand[i] = Constants::NULL_TERMINATOR;
            //Serial.print("Command extracted: ");
            //Serial.println(extractedCommand);
            didExtract = true;
            break;
        } 
        extractedCommand[i] = receivedBytes[i];
    }
    
    if(receivedBytes[i] == Constants::NULL_TERMINATOR || strcmp_P(extractedCommand, "ls") == 0) {
      return;
    }

    i++;
    int j = 0;
    for(i; i < Constants::MAX_INPUT_SIZE; i++) {
      if(receivedBytes[i] == Constants::NULL_TERMINATOR || receivedBytes[i] == ' ') {
        extractedArgument[j] = Constants::NULL_TERMINATOR;
        return;
      }
      extractedArgument[j] = receivedBytes[i];
      j++;
    }

    
}



CommandProcessor::CommandProcessor() {
  //Initialize FileSystem instance
}

void CommandProcessor::lookUpAndRun(const char *receivedBytes) {
    bool didExtract = false;
    char extractedCommand[Constants::MAX_COMMAND_SIZE];
    
    extractCommand(receivedBytes, extractedCommand, extractedArgument, didExtract);
    
    if(!didExtract) {
      return;
    }

    for (int i = 0; i < mapSize; i++) {
      auto* key = (const char*)pgm_read_ptr(&(commandMap[i].key));
      if(strcmp_P(extractedCommand, key) == 0) {
        void (CommandProcessor::*funcPtr)(void);
        memcpy_P(&funcPtr, &(commandMap[i].funcPtr), sizeof(funcPtr));
        (this->*funcPtr)();
        return;
      }
    }

Serial.print("Invalid Command Entered: ");
Serial.print(extractedCommand);
Serial.println();
}

void CommandProcessor::changeDirectory() {
  Serial.println("Entered Change Directory function!");
}

void CommandProcessor::createDirectory() {
    Serial.println("Entered create Directory function!");
}

void CommandProcessor::createFile() {
  fls.createFile(extractedArgument);
}

void CommandProcessor::list() {
    Serial.println("Entered list");
    fls.list();
}

