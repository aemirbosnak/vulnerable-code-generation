//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void toMorse(char *text, char *morse);
void printMorse(char *morse);
void help();

int main(int argc, char *argv[]) {
  char text[MAX_LEN];
  char morse[MAX_LEN];

  if (argc == 1) {
    help();
    return 0;
  } else if (argc == 2) {
    strcpy(text, argv[1]);
  } else {
    printf("Too many arguments\n\n");
    help();
    return 1;
  }

  toMorse(text, morse);
  printMorse(morse);

  return 0;
}

void toMorse(char *text, char *morse) {
  int i, j;
  char *morseCodes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
  };

  for (i = 0, j = 0; text[i]; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= 32;
    }

    if (text[i] >= 'A' && text[i] <= 'Z') {
      strcpy(&morse[j], morseCodes[text[i] - 'A']);
      j += strlen(morseCodes[text[i] - 'A']);
      morse[j++] = ' ';
    }
  }

  morse[j] = '\0';
}

void printMorse(char *morse) {
  printf("%s\n", morse);
}

void help() {
  printf("Usage: morse <text>\n");
  printf("\nConverts text to Morse code.\n");
  printf("\nArguments:\n");
  printf("  text: The text to convert to Morse code.\n");
}