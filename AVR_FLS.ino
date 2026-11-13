#include <EEPROM.h>
#include "Constants.h"
#include "CommandProcessor.h"



#define SERIAL_RATE 9600
char receivedBytes[Constants::MAX_INPUT_SIZE];

CommandProcessor* cmdProc;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  while (!Serial);
  Serial.flush();

  cmdProc = new CommandProcessor();
}

void loop() {
  Serial.print("$: ");
  parseInput();
  Serial.println();
  cmdProc->lookUpAndRun(receivedBytes);
}

void parseInput() {
  int idx = 0;

  while (true) {
    if (Serial.available() > 0) {
      char temp = Serial.read();

      if (temp == '\n') break;

      if (idx < Constants::MAX_INPUT_SIZE - 1) {
        receivedBytes[idx] = temp;
        idx++;
      }
    }
  }
  receivedBytes[idx] = '\0';
}
