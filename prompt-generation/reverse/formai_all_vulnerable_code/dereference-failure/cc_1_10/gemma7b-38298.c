//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_MORSE_CODE_LENGTH 20

typedef struct MorseCodeEntry {
  char letter;
  char* code;
} MorseCodeEntry;

MorseCodeEntry* createMorseCodeEntry(char letter, char* code) {
  MorseCodeEntry* entry = malloc(sizeof(MorseCodeEntry));
  entry->letter = letter;
  entry->code = strdup(code);
  return entry;
}

void printMorseCode(MorseCodeEntry* entry) {
  printf("%c: ", entry->letter);
  printf("%s\n", entry->code);
}

int main() {
  MorseCodeEntry* entries[] = {
    createMorseCodeEntry('a', ".-"),
    createMorseCodeEntry('b', "-"),
    createMorseCodeEntry('c', "-.."),
    createMorseCodeEntry('d', "."),
    createMorseCodeEntry('e', ".."),
    createMorseCodeEntry('f', "..-."),
    createMorseCodeEntry('g', "--"),
    createMorseCodeEntry('h', "...."),
    createMorseCodeEntry('i', ".."),
    createMorseCodeEntry('j', ".---"),
    createMorseCodeEntry('k', "-.."),
    createMorseCodeEntry('l', ".-.."),
    createMorseCodeEntry('m', "--."),
    createMorseCodeEntry('n', "-."),
    createMorseCodeEntry('o', "---"),
    createMorseCodeEntry('p', ".--"),
    createMorseCodeEntry('q', "--."),
    createMorseCodeEntry('r', ".-"),
    createMorseCodeEntry('s', "..."),
    createMorseCodeEntry('t', "-"),
    createMorseCodeEntry('u', "..-"),
    createMorseCodeEntry('v', "...-"),
    createMorseCodeEntry('w', ".--"),
    createMorseCodeEntry('x', "-.."),
    createMorseCodeEntry('y', "--.."),
    createMorseCodeEntry('z', "---")
  };

  for (int i = 0; i < 28; i++) {
    printMorseCode(entries[i]);
  }

  return 0;
}