#pragma once
#include "Constants.h"


class CommandProcessor {

public:
    CommandProcessor() {

    }
    void changeDirectory() {
        //TODO CHANGE DIRECTORY OR RETURN TO ROOT
    }
    void list() {
        //TODO SHOW FILES IN DIRECTORY
    }
    void createDirectory() {
        //TODO CREATE DIRECTORY
    }

private:



};

struct KeyValuePair {
    const char *key;
    void (CommandProcessor::*funcPtr)(void);
};

const char cd_str[] PROGMEM = "cd";
const char ls_str[] PROGMEM = "ls";
const char mkdir_str[] PROGMEM = "mkdir";
const KeyValuePair commandMap[] PROGMEM= {
  {cd_str, &CommandProcessor::changeDirectory},
  {ls_str, &CommandProcessor::list},
  {mkdir_str, &CommandProcessor::createDirectory}
};