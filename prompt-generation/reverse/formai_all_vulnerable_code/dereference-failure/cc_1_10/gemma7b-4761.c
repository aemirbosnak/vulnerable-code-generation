//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word *words = NULL;

void analyze_text(char *text) {
  char *words_ptr = strtok(text, " ");
  char **words_array = NULL;
  int i = 0;

  while (words_ptr) {
    words_array = realloc(words_array, (i + 1) * sizeof(char *));
    words_array[i++] = strdup(words_ptr);
    words_ptr = strtok(NULL, " ");
  }

  words = malloc(MAX_WORDS * sizeof(Word));
  for (i = 0; i < MAX_WORDS; i++) {
    words[i].word = NULL;
    words[i].frequency = 0;
  }

  for (i = 0; words_array[i] != NULL; i++) {
    Word *w = words;
    for (int j = 0; w->word != NULL; j++) {
      if (strcmp(w->word, words_array[i]) == 0) {
        w->frequency++;
      }
    }
    free(words_array[i]);
  }

  free(words_array);
}

int main() {
  char *text = "This is a sample text that contains some spam words, such as buy, sell, and make. It also contains some nonspam words, such as apple, banana, and orange.";

  analyze_text(text);

  for (int i = 0; words[i].word != NULL; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  return 0;
}