//LLAMA2-13B DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_INPUT 1024
#define MAX_STRLEN 256

// Generate a random poem using the input words
void generate_poem(char **words, int num_words) {
  int i, j, k, l;
  int word_index = 0;
  char *current_word = NULL;
  char *previous_word = NULL;
  char *poem = NULL;
  int poem_len = 0;

  // Generate a random word from the input words
  for (i = 0; i < num_words; i++) {
    current_word = words[i];
    word_index = rand() % num_words;
    while (word_index == i) {
      word_index = (word_index + 1) % num_words;
    }
    previous_word = current_word;
    current_word = words[word_index];
    poem_len += strlen(current_word) + 1;
    poem = realloc(poem, poem_len);
    if (poem == NULL) {
      printf("Error: Poem allocation failed\n");
      exit(EXIT_FAILURE);
    }
    strcat(poem, current_word);
    if (previous_word != NULL) {
      strcat(poem, " ");
    }
  }
  printf("Generated poem: %s\n", poem);
  free(poem);
}

int main() {
  int num_words = 5;
  char *words[num_words];

  // Generate the input words
  for (int i = 0; i < num_words; i++) {
    words[i] = malloc(MAX_STRLEN);
    if (words[i] == NULL) {
      printf("Error: Word allocation failed\n");
      exit(EXIT_FAILURE);
    }
    fgets(words[i], MAX_STRLEN, stdin);
  }

  // Generate the poem
  generate_poem(words, num_words);

  return 0;
}