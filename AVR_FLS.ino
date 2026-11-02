
#define SERIAL_RATE 9600
const int MAX_INPUT_SIZE = 32;
char receivedBytes[MAX_INPUT_SIZE];



void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  Serial.flush();
}

void loop() {
  parseInput();
  Serial.print(receivedBytes);
}

void parseInput() {
  int idx = 0;

  while (true) {
    if (Serial.available() > 0) {
      char temp = Serial.read();

      if (temp == '\n') break;

      if (idx < MAX_INPUT_SIZE - 1) {
        receivedBytes[idx] = temp;
        idx++;
      }
    }
  }
  receivedBytes[idx] = '\0';
}
