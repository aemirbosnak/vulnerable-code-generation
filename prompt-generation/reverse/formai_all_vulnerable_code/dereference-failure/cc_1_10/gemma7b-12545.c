//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word *words;

void analyze_text(char *text) {
  char *words_ptr = text;
  Word *word_ptr = words;

  while (words_ptr) {
    char *word = malloc(MAX_WORDS);
    strcpy(word, words_ptr);

    int found = 0;
    for (Word *w = words; w; w++) {
      if (strcmp(word, w->word) == 0) {
        w->frequency++;
        found = 1;
      }
    }

    if (!found) {
      Word *new_word = malloc(sizeof(Word));
      new_word->word = word;
      new_word->frequency = 1;
      words_ptr = word;
      words = new_word;
    }

    words_ptr += strlen(word) + 1;
  }
}

int main() {
  words = NULL;

  char *text = "This is a sample text with some spam words, such as 'miracle' and 'free'.";

  analyze_text(text);

  for (Word *w = words; w; w++) {
    printf("%s: %d\n", w->word, w->frequency);
  }

  return 0;
}