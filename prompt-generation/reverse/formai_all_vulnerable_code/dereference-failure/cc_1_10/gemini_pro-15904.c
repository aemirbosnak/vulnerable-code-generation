//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char morse_code[][6] = {
  ".-",   "-...", "-.-.", "-..",  ".",
  "..-.", "--.",  "....", "..",   ".---",
  "-.-",  ".-..", "--",    "-.",   "...",
  "-",    "..-",  "...-", ".--",  "-..-",
  "-.--", "--..", ".-",    "..."
};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
  int len = strlen(text);
  char *morse = malloc(len * 5 + 1);
  int i, j, k = 0;

  for (i = 0; i < len; i++) {
    char c = text[i];
    if (c >= 'a' && c <= 'z') {
      c -= 32;
    }
    for (j = 0; j < 26; j++) {
      if (c == 'A' + j) {
        strcat(morse, morse_code[j]);
        strcat(morse, " ");
        k += strlen(morse_code[j]) + 1;
        break;
      }
    }
    if (c == ' ') {
      strcat(morse, "  ");
      k += 2;
    }
  }

  morse[k] = '\0';
  return morse;
}

// Main function
int main() {
  char text[] = "HELLO WORLD";
  char *morse = text_to_morse(text);

  printf("Text: %s\n", text);
  printf("Morse code: %s\n", morse);

  free(morse);
  return 0;
}