//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MORSE_CODE_SIZE 26

typedef struct MorseNode {
  char character;
  char *code;
} MorseNode;

MorseNode morse_code[MORSE_CODE_SIZE] = {
  { 'a', ".-" },
  { 'b', "-..." },
  { 'c', "-.-." },
  { 'd', "-.." },
  { 'e', "." },
  { 'f', "..-." },
  { 'g', "--." },
  { 'h', "...." },
  { 'i', ".." },
  { 'j', ".---" },
  { 'k', "-.-" },
  { 'l', ".-.." },
  { 'm', "--" },
  { 'n', "-." },
  { 'o', "---" },
  { 'p', ".--." },
  { 'q', "--.-" },
  { 'r', ".-." },
  { 's', "..." },
  { 't', "-" },
  { 'u', "..-." },
  { 'v', "...-" },
  { 'w', ".--" },
  { 'x', "-..-." },
  { 'y', "-.--" },
  { 'z', "--.." }
};

void print_morse_code(const char *text) {
  if (!text || *text == '\0') {
    return;
  }

  char ch = *text;
  int i;
  for (i = 0; i < MORSE_CODE_SIZE; i++) {
    if (ch == morse_code[i].character) {
      printf("%s ", morse_code[i].code);
      break;
    }
  }

  print_morse_code(text + 1);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *text = argv[1];
  printf("Morse code for '%s': ", text);
  print_morse_code(text);
  printf("\n");

  return EXIT_SUCCESS;
}