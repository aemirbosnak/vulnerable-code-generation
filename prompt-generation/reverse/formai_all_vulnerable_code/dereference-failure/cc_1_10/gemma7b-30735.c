//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void alien_translator(char **buffer) {
  int i, j, k, alien_length, human_length;
  char alien_word[MAX_BUFFER_SIZE], human_word[MAX_BUFFER_SIZE];
  char temp_char;

  alien_length = strlen(*buffer);
  human_length = alien_length * 2;

  for (i = 0; i < alien_length; i++) {
    temp_char = (*buffer)[i];
    switch (temp_char) {
      case 'a':
        alien_word[i] = 'z';
        break;
      case 'e':
        alien_word[i] = 'y';
        break;
      case 'i':
        alien_word[i] = 'r';
        break;
      case 'o':
        alien_word[i] = 'a';
        break;
      default:
        alien_word[i] = temp_char;
    }
  }

  alien_word[alien_length] = '\0';
  strcpy(human_word, alien_word);

  for (j = 0; j < human_length; j++) {
    switch (human_word[j]) {
      case 'z':
        human_word[j] = 'a';
        break;
      case 'y':
        human_word[j] = 'e';
        break;
      case 'r':
        human_word[j] = 'i';
        break;
      case 'a':
        human_word[j] = 'o';
        break;
      default:
        human_word[j] = human_word[j];
    }
  }

  human_word[human_length] = '\0';

  printf("Human translation: %s\n", human_word);
}

int main() {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  printf("Enter an alien message: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  alien_translator(&buffer);

  free(buffer);

  return 0;
}