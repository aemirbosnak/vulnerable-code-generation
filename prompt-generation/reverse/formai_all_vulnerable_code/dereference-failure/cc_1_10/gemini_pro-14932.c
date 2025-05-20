//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char letter;
  char* morse;
} morse_code;

morse_code morse_table[] = {
  { 'A', ".-"},
  { 'B', "-..."},
  { 'C', "-.-."},
  { 'D', "-.."},
  { 'E', "."},
  { 'F', "..-."},
  { 'G', "--."},
  { 'H', "...."},
  { 'I', ".."},
  { 'J', ".---"},
  { 'K', "-.-"},
  { 'L', ".-.."},
  { 'M', "--"},
  { 'N', "-."},
  { 'O', "---"},
  { 'P', ".--."},
  { 'Q', "--.-"},
  { 'R', ".-."},
  { 'S', "..."},
  { 'T', "-"},
  { 'U', "..-"},
  { 'V', "...-"},
  { 'W', ".--"},
  { 'X', "-..-"},
  { 'Y', "-.--"},
  { 'Z', "--.."},
  { '0', "-----"},
  { '1', ".----"},
  { '2', "..---"},
  { '3', "...--"},
  { '4', "....-"},
  { '5', "....."},
  { '6', "-...."},
  { '7', "--..."},
  { '8', "---.."},
  { '9', "----."},
  { ' ', " "},
  { '\n', "\n"},
};

char* morse_encode(char* text) {
  char* morse = malloc(strlen(text) * 5);
  char* p = morse;
  while (*text) {
    char* m = NULL;
    for (int i = 0; i < sizeof(morse_table) / sizeof(morse_code); i++) {
      if (*text == morse_table[i].letter) {
        m = morse_table[i].morse;
        break;
      }
    }
    if (!m) {
      *p++ = *text;
    } else {
      while (*m) {
        *p++ = *m++;
      }
      *p++ = ' ';
    }
    text++;
  }
  *p = '\0';
  return morse;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s text\n", argv[0]);
    return 1;
  }
  char* morse = morse_encode(argv[1]);
  printf("%s\n", morse);
  free(morse);
  return 0;
}