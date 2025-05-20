//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>

#define MAX_Morse_CODE_LENGTH 10

void translate_word_to_morse_code(char *word) {
  char **morse_code_table = {".-", "-...", "-.-.", ".---", "-..", "--.", "....", "..", ".---", "-..-"};
  int i = 0;

  for (i = 0; word[i] != '\0'; i++) {
    switch (word[i]) {
      case 'a':
        printf("%s ", morse_code_table[0]);
        break;
      case 'b':
        printf("%s ", morse_code_table[1]);
        break;
      case 'c':
        printf("%s ", morse_code_table[2]);
        break;
      case 'd':
        printf("%s ", morse_code_table[3]);
        break;
      case 'e':
        printf("%s ", morse_code_table[4]);
        break;
      case 'f':
        printf("%s ", morse_code_table[5]);
        break;
      case 'g':
        printf("%s ", morse_code_table[6]);
        break;
      case 'h':
        printf("%s ", morse_code_table[7]);
        break;
      case 'i':
        printf("%s ", morse_code_table[8]);
        break;
      case 'j':
        printf("%s ", morse_code_table[9]);
        break;
      default:
        printf("Invalid character\n");
    }
  }

  printf("\n");
}

int main() {
  char word[MAX_Morse_CODE_LENGTH] = "HELLO WORLD!";

  translate_word_to_morse_code(word);

  return 0;
}