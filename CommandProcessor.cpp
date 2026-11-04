#include "CommandProcessor.h"
#include "Constants.h"

void extractCommand(const char *receivedBytes, char* extractedCommand) {
    for(uint8_t i = 0; i < Constants::MAX_COMMAND_SIZE; i++) {
        if(receivedBytes[i] == Constants::NULL_TERMINATOR || receivedBytes[i] == ' ') {
            extractedCommand[i] = Constants::NULL_TERMINATOR;
            cout << "Command extracted: " << extractedCommand << endl;
            return;
        }
        extractedCommand[i] = receivedBytes[i];
    }
    cout << "Error invalid command!" << endl;
}

void CommandProcessor::lookUp(const char *receivedBytes) {
    
    char extractedCommand[Constants::MAX_COMMAND_SIZE];
    extractCommand(receivedBytes, extractedCommand);
}

//