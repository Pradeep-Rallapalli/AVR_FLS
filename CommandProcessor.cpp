#include "CommandProcessor.h"
#include "Constants.h"

struct KeyValuePair {
    const char *key;
    void (CommandProcessor::*funcPtr)(void);
  };

const char cd_str[] PROGMEM = "cd";
const char ls_str[] PROGMEM = "ls";
const char mkdir_str[] PROGMEM = "mkdir";

  const KeyValuePair commandMap[] PROGMEM = {
    {cd_str, &CommandProcessor::changeDirectory},
    {ls_str, &CommandProcessor::list},
    {mkdir_str, &CommandProcessor::createDirectory}
  };

const uint8_t mapSize = sizeof(commandMap) / sizeof(KeyValuePair);

void extractCommand(const char* receivedBytes, char* extractedCommand, bool& didExtract) {
    for(uint8_t i = 0; i < Constants::MAX_COMMAND_SIZE; i++) {
        if(receivedBytes[i] == Constants::NULL_TERMINATOR || receivedBytes[i] == ' ') {
            extractedCommand[i] = Constants::NULL_TERMINATOR;
            Serial.print("Command extracted: ");
            Serial.println(extractedCommand);
            didExtract = true;
            return;
        }
        extractedCommand[i] = receivedBytes[i];
    }
    didExtract = false;
    Serial.println("INVALID COMMAND ENTERED!");
}

/*

Last left off at trying to see if user input can hit a match on the map.
Having trouble extracting key and comparing it to user input. 
First understand how key is extracted then try.

*/

void CommandProcessor::lookUpAndRun(const char *receivedBytes) {
    bool didExtract = false;
    char extractedCommand[Constants::MAX_COMMAND_SIZE];
    extractCommand(receivedBytes, extractedCommand, didExtract);
    
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

Serial.println("Lookup and run failed!");
}

void CommandProcessor::changeDirectory() {
  Serial.println("Entered Change Directory function!");
}

void CommandProcessor::createDirectory() {
    Serial.println("Entered create Directory function!");
}

void CommandProcessor::list() {
    Serial.println("Entered list Directory function!");
}

//