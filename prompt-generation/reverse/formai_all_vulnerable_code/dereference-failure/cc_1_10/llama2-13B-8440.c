//LLAMA2-13B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3
#define PAD_CHAR '*'

// Function to generate a random word
void generate_word(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }
  for (j = 0; j < MIN_WORD_LENGTH; j++) {
    word[i + j] = PAD_CHAR;
  }
}

// Function to check if a word is valid
int is_valid_word(const char *word) {
  int i;
  for (i = 0; i < strlen(word); i++) {
    if (word[i] == PAD_CHAR) {
      continue;
    }
    if (!isalnum(word[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to print the word
void print_word(const char *word) {
  int i;
  for (i = 0; i < strlen(word); i++) {
    putchar(word[i]);
  }
  putchar('\n');
}

int main() {
  char word[MAX_WORD_LENGTH];
  generate_word(word);
  print_word(word);
  if (is_valid_word(word)) {
    printf("Valid word: %s\n", word);
  } else {
    printf("Invalid word: %s\n", word);
  }
  return 0;
}