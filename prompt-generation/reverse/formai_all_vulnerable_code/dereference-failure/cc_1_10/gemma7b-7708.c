//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

char morse_code[4] = {'.---', '-..---', '-..', '.---.'};

void translate_text_to_morse(char text[]) {
  int i = 0;
  char word[20];
  word[0] = '\0';

  while (text[i] != '\0') {
    char letter = text[i];
    switch (letter) {
      case 'a':
      case 'A':
        strcat(word, morse_code[0]);
        break;
      case 'b':
      case 'B':
        strcat(word, morse_code[1]);
        break;
      case 'c':
      case 'C':
        strcat(word, morse_code[2]);
        break;
      case 'd':
      case 'D':
        strcat(word, morse_code[3]);
        break;
      default:
        break;
    }

    if (word[0] != '\0') {
      printf("%s ", word);
      word[0] = '\0';
    }

    i++;
  }

  printf("\n");
}

int main() {
  char text[] = "Hello, world!";

  translate_text_to_morse(text);

  return 0;
}