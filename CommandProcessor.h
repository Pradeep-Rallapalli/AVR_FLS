#pragma once
#include "Constants.h"
#include "FileSystem.h"


class CommandProcessor {

public:
    CommandProcessor();
    void lookUpAndRun(const char* receivedBytes);
    void changeDirectory();
    void list();
    void createDirectory();
    void createFile();

private:
FileSystem fls;
char extractedArgument[Constants::MAX_NAME_LENGTH];
};

