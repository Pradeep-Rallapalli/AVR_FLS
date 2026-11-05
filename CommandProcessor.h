#pragma once
#include "Constants.h"


class CommandProcessor {

public:
    //CommandProcessor();
    void lookUpAndRun(const char* receivedBytes);
    void changeDirectory();
    void list();
    void createDirectory();

private: 
  
};

