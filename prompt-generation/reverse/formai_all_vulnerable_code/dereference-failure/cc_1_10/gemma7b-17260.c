//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Morse_CODE_LENGTH 10

typedef struct MorseCode {
  char symbol;
  char code[MAX_Morse_CODE_LENGTH];
} MorseCode;

MorseCode* createMorseCode(char symbol, char* code) {
  MorseCode* mc = malloc(sizeof(MorseCode));
  mc->symbol = symbol;
  strcpy(mc->code, code);
  return mc;
}

void printMorseCode(MorseCode* mc) {
  printf("%c: ", mc->symbol);
  for (int i = 0; mc->code[i] != '\0'; i++) {
    switch (mc->code[i]) {
      case '.':
        printf(".- ");
        break;
      case '-':
        printf("-.. ");
        break;
      case '_':
        printf("... ");
        break;
      case '/':
        printf("..- ");
        break;
      default:
        printf("Error: Invalid Morse code character.");
    }
  }
  printf("\n");
}

int main() {
  MorseCode* mc = createMorseCode('A', ".---");
  printMorseCode(mc);

  mc = createMorseCode('B', "-....");
  printMorseCode(mc);

  mc = createMorseCode('C', "-..");
  printMorseCode(mc);

  mc = createMorseCode('D', ".");
  printMorseCode(mc);

  mc = createMorseCode('E', "");
  printMorseCode(mc);

  return 0;
}