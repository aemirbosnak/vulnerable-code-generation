//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_Morse_CODE_LENGTH 30

typedef struct MorseCode {
  char character;
  char* code;
} MorseCode;

MorseCode* createMorseCode(char character, char* code) {
  MorseCode* mc = (MorseCode*)malloc(sizeof(MorseCode));
  mc->character = character;
  mc->code = code;
  return mc;
}

void printMorseCode(MorseCode* mc) {
  printf("%c is encoded as:", mc->character);
  for (int i = 0; mc->code[i] != '\0'; i++) {
    switch (mc->code[i]) {
      case '.':
        printf(".- ");
        break;
      case '-':
        printf("-.. ");
        break;
      case '_':
        printf(". ");
        break;
      case ' ':
        printf("/ ");
        break;
    }
  }
  printf("\n");
}

int main() {
  MorseCode* mc = createMorseCode('a', ".---");
  printMorseCode(mc);

  mc = createMorseCode('b', "-....");
  printMorseCode(mc);

  mc = createMorseCode('c', "-..");
  printMorseCode(mc);

  mc = createMorseCode('d', ".---");
  printMorseCode(mc);

  mc = createMorseCode('e', "..---");
  printMorseCode(mc);

  return 0;
}